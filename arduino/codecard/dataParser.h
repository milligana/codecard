/*
  dataParser.h
  
*/

void parseJson(String jsonString) {  
  // WAM - can be up to 9 template/descriptor keys in our JSON object
  Serial.println(F("JSON Payload"));
  Serial.println(jsonString);
  const int capacity = JSON_OBJECT_SIZE(99);
  //DynamicJsonDocument doc(capacity);
  StaticJsonDocument<capacity> doc;
  DeserializationError error = deserializeJson(doc, jsonString);

  if (error) {
    Serial.println(F("JSON deserializaion failed"));
    Serial.println(error.c_str());
    Serial.println(jsonString);
    return;
  }

  /* WAM
  
  JsonObject root = jsonBuffer.as<JsonObject>(); // get the root object

  String jsonStr;
  serializeJson(root, jsonStr);
  Serial.println(F("Response: "));
  Serial.println("  " + jsonStr);
  Serial.println(F(">>>"));

  if (!root.isNull()) {
    Serial.println(F("JSON parsing failed!"));
    Serial.println(F(">>>"));
    template1("Invalid response", "Please verify JSON",  jsonString ,"fail","","", "");
    //saveToMemory(getKeyIndex("showdefaultscreen"), "true");
    return;
  }
  */
  
  //saveToMemory(getKeyIndex("lastpayload"), jsonStr);
  
  String templateName = doc["template"].as<String>();
  String title = doc["title"].as<String>();
  String subtitle = doc["subtitle"].as<String>();
  String body = doc["bodytext"].as<String>();
  String icon = doc["icon"].as<String>();
  String backgroundImage = doc["backgroundImage"].as<String>();
  String backgroundColor = doc["backgroundColor"].as<String>();
  String badge = doc["badge"].as<String>();
  String fingerprint = doc["fingerprint"].as<String>();
  String barcode = doc["barcode"].as<String>();

  Serial.print(F("Icon = "));
  Serial.println(icon);

  if (templateName == "custom"){
    String titleFont = doc["titleFont"].as<String>();
    String titleX = doc["titleX"].as<String>();
    String titleY = doc["titleY"].as<String>();
    String subtitleFont = doc["subtitleFont"].as<String>();
    String subTitleX = doc["subTitleX"].as<String>();
    String subTitleY = doc["subTitleY"].as<String>();
    String bodyFont = doc["bodyFont"].as<String>();
    String bodyX = doc["bodyX"].as<String>();
    String bodyY = doc["bodyY"].as<String>();
    String iconX = doc["iconX"].as<String>();
    String iconY = doc["iconY"].as<String>();
    custom();
  }
  

  // WAM dynamic only???  doc.clear();
    
  // Serial.println("Free HEAP: " + String(ESP.getFreeHeap()));
  
  saveToMemory(getKeyIndex("showdefaultscreen"), "false");
  
  if (templateName == "template1") {
    template1(title, subtitle, body, icon, badge, backgroundColor, fingerprint);
  } else if (templateName == "template2") {
    template2(title, subtitle, body, icon, badge, backgroundColor, fingerprint);
  } else if (templateName == "template3") {
    template3(title, subtitle, body, icon, badge, backgroundColor, fingerprint);
  } else if (templateName == "template4") {
    template4(title, subtitle, body, icon, badge, backgroundColor, fingerprint);
  } else if (templateName == "template5") {
    template5(title, subtitle, body, backgroundColor);
  } else if (templateName == "template6") {
    template6(title, subtitle, body, backgroundColor);    
  } else if (templateName == "template7") {
    template7(title, subtitle, backgroundColor, backgroundImage, fingerprint);    
  } else if (templateName == "template8") {
    template8(backgroundColor, backgroundImage, fingerprint); 
  } else if (templateName == "template9") {
    template9(title, subtitle, backgroundColor);
  } else if (templateName == "template10") {
    template10(title, subtitle, body, backgroundColor, barcode);    
  } else if (templateName == "template11") {
    template11(title, subtitle, icon, badge, backgroundColor, fingerprint);                 
  } else {
    template1("Invalid response", "Please verify JSON",  jsonString ,"fail","","", "");
    saveToMemory(getKeyIndex("showdefaultscreen"), "true");
  }
  
}

void parseJsonObject(JsonObject& root) {
  String jsonStr;
  serializeJson(root, jsonStr);
  parseJson(jsonStr);
}


void displayImageFromUrlTest(WiFiClient& client, int16_t x, int16_t y, bool connection_ok, bool with_color) {
  bool valid = false; // valid format to be handled
  bool flip = true; // bitmap is stored bottom-to-top
  
  int c = '\0';
  unsigned long startTime = millis();
  unsigned long httpResponseTimeOut = 10000; // 10 sec
  
  if (read16(client) == 0x4D42) // BMP signature
  {
    uint32_t fileSize = read32(client);
    uint32_t creatorBytes = read32(client);
    uint32_t imageOffset = read32(client); // Start of image data
    uint32_t headerSize = read32(client);
    uint32_t width  = read32(client);
    uint32_t height = read32(client);
    uint16_t planes = read16(client);
    uint16_t depth = read16(client); // bits per pixel
    uint32_t format = read32(client);
    uint32_t bytes_read = 7 * 4 + 3 * 2; // read so far
    if ((planes == 1) && ((format == 0) || (format == 3))) // uncompressed is handled, 565 also
    {
      Serial.print("File size: "); Serial.println(fileSize);
      Serial.print("Image Offset: "); Serial.println(imageOffset);
      Serial.print("Header size: "); Serial.println(headerSize);
      Serial.print("Bit Depth: "); Serial.println(depth);
      Serial.print("Image size: ");
      Serial.print(width);
      Serial.print('x');
      Serial.println(height);
      // BMP rows are padded (if needed) to 4-byte boundary
      uint32_t rowSize = (width * depth / 8 + 3) & ~3;
      if (height < 0)
      {
        height = -height;
        flip = false;
      }
      uint16_t w = width;
      uint16_t h = height;
      if ((x + w - 1) >= display.width())  w = display.width()  - x;
      if ((y + h - 1) >= display.height()) h = display.height() - y;

      // works for small icons
      y = (display.height() - height) + y;

      Serial.print("x: "); Serial.println(x);
      Serial.print("y: "); Serial.println(y);
      Serial.print("display.width(): "); Serial.println(display.width());
      Serial.print("display.height(): "); Serial.println(display.height());
    }
  }

  
  while (client.connected() && ((millis() - startTime) < httpResponseTimeOut)) {
    if (client.available()) {
      c = client.read();
      // Serial.print((char)c);
    }
    else {
      Serial.print(".");
      delay(100);
    }
  }

  
}

void displayImageFromUrl(WiFiClient& client, int16_t x, int16_t y, bool connection_ok, bool with_color) {
  bool valid = false; // valid format to be handled
  bool flip = true; // bitmap is stored bottom-to-top
  uint32_t startTime = millis();  

  display.setRotation(0);
  
  // Parse BMP header
  if (read16(client) == 0x4D42) // BMP signature
  {
    uint32_t fileSize = read32(client);
    uint32_t creatorBytes = read32(client);
    uint32_t imageOffset = read32(client); // Start of image data
    uint32_t headerSize = read32(client);
    uint32_t width  = read32(client);
    uint32_t height = read32(client);
    uint16_t planes = read16(client);
    uint16_t depth = read16(client); // bits per pixel
    uint32_t format = read32(client);
    uint32_t bytes_read = 7 * 4 + 3 * 2; // read so far
    if ((planes == 1) && ((format == 0) || (format == 3))) // uncompressed is handled, 565 also
    {
      Serial.print("  File size: "); Serial.println(fileSize);
      Serial.print("  Image Offset: "); Serial.println(imageOffset);
      Serial.print("  Header size: "); Serial.println(headerSize);
      Serial.print("  Bit Depth: "); Serial.println(depth);
      Serial.print("  Image size: ");
      Serial.print(width);
      Serial.print('x');
      Serial.println(height);
      // BMP rows are padded (if needed) to 4-byte boundary
      uint32_t rowSize = (width * depth / 8 + 3) & ~3;
      if (height < 0)
      {
        height = -height;
        flip = false;
      }
      uint16_t w = width;
      uint16_t h = height;
      if ((x + w - 1) >= display.width())  w = display.width()  - x;
      if ((y + h - 1) >= display.height()) h = display.height() - y;

      // works for small icons
      y = (display.height() - height) + y;

//      Serial.print("x: "); Serial.println(x);
//      Serial.print("y: "); Serial.println(y);
//      Serial.print("display.width(): "); Serial.println(display.width());
//      Serial.print("display.height(): "); Serial.println(display.height());
    
      if (w < max_row_width) // handle with direct drawing
      {
        valid = true;
        uint8_t bitmask = 0xFF;
        uint8_t bitshift = 8 - depth;
        uint16_t red, green, blue;
        bool whitish, colored;
        if (depth == 1) with_color = false;
        if (depth <= 8)
        {
          if (depth < 8) bitmask >>= depth;
          bytes_read += skip(client, 54 - bytes_read); //palette is always @ 54
          for (uint16_t pn = 0; pn < (1 << depth); pn++)
          {
            blue  = client.read();
            green = client.read();
            red   = client.read();
            client.read();
            bytes_read += 4;
            whitish = with_color ? ((red > 0x80) && (green > 0x80) && (blue > 0x80)) : ((red + green + blue) > 3 * 0x80); // whitish
            colored = (red > 0xF0) || ((green > 0xF0) && (blue > 0xF0)); // reddish or yellowish?
            if (0 == pn % 8) mono_palette_buffer[pn / 8] = 0;
            mono_palette_buffer[pn / 8] |= whitish << pn % 8;
            if (0 == pn % 8) color_palette_buffer[pn / 8] = 0;
            color_palette_buffer[pn / 8] |= colored << pn % 8;
            //Serial.print("0x00"); Serial.print(red, HEX); Serial.print(green, HEX); Serial.print(blue, HEX);
            //Serial.print(" : "); Serial.print(whitish); Serial.print(", "); Serial.println(colored);
          }
        }
        //display.writeScreenBuffer();
        uint32_t rowPosition = flip ? imageOffset + (height - h) * rowSize : imageOffset;
        //Serial.print("skip "); Serial.println(rowPosition - bytes_read);
        bytes_read += skip(client, rowPosition - bytes_read);
        for (uint16_t row = 0; row < h; row++, rowPosition += rowSize) // for each line
        {
          if (!connection_ok || !client.connected()) break;
          delay(1); // yield() to avoid WDT
          uint32_t in_remain = rowSize;
          uint32_t in_idx = 0;
          uint32_t in_bytes = 0;
          uint8_t in_byte = 0; // for depth <= 8
          uint8_t in_bits = 0; // for depth <= 8
          uint8_t out_byte = 0;
          uint8_t out_color_byte = 0;
          uint32_t out_idx = 0;
          for (uint16_t col = 0; col < w; col++) // for each pixel
          {
            yield();
            if (!connection_ok || !client.connected()) break;
            // Time to read more pixel data?
            if (in_idx >= in_bytes) // ok, exact match for 24bit also (size IS multiple of 3)
            {
              uint32_t get = in_remain > sizeof(input_buffer) ? sizeof(input_buffer) : in_remain;
              //if (get > client.available()) delay(200); // does improve? yes, if >= 200
              // there seems an issue with long downloads on ESP8266
              tryToWaitForAvailable(client, get);
              uint32_t got = client.read(input_buffer, get);
              while ((got < get) && connection_ok)
              {
                //Serial.print("got "); Serial.print(got); Serial.print(" < "); Serial.print(get); Serial.print(" @ "); Serial.println(bytes_read);
                //if ((get - got) > client.available()) delay(200); // does improve? yes, if >= 200
                // there seems an issue with long downloads on ESP8266
                tryToWaitForAvailable(client, get - got);
                uint32_t gotmore = client.read(input_buffer + got, get - got);
                got += gotmore;
                // Serial.println(gotmore);
                connection_ok = gotmore > 0;
              }
              //Serial.print("got "); Serial.print(got); Serial.print(" < "); Serial.print(get); Serial.print(" @ "); Serial.print(bytes_read); Serial.print(" of "); Serial.println(fileSize);
              //Serial.print("  "); Serial.print(bytes_read); Serial.print(" of "); Serial.print(fileSize); Serial.println(" bytes");
              in_bytes = got;
              in_remain -= got;
              bytes_read += got;
            }
            if (!connection_ok)
            {
              Serial.print("  Error: no more data after "); Serial.print(bytes_read); Serial.println(" bytes.");
              break;
            }
            switch (depth)
            {
              case 24:
                blue = input_buffer[in_idx++];
                green = input_buffer[in_idx++];
                red = input_buffer[in_idx++];
                whitish = with_color ? ((red > 0x80) && (green > 0x80) && (blue > 0x80)) : ((red + green + blue) > 3 * 0x80); // whitish
                colored = (red > 0xF0) || ((green > 0xF0) && (blue > 0xF0)); // reddish or yellowish?
                break;
              case 16:
                {
                  uint8_t lsb = input_buffer[in_idx++];
                  uint8_t msb = input_buffer[in_idx++];
                  if (format == 0) // 555
                  {
                    blue  = (lsb & 0x1F) << 3;
                    green = ((msb & 0x03) << 6) | ((lsb & 0xE0) >> 2);
                    red   = (msb & 0x7C) << 1;
                  }
                  else // 565
                  {
                    blue  = (lsb & 0x1F) << 3;
                    green = ((msb & 0x07) << 5) | ((lsb & 0xE0) >> 3);
                    red   = (msb & 0xF8);
                  }
                  whitish = with_color ? ((red > 0x80) && (green > 0x80) && (blue > 0x80)) : ((red + green + blue) > 3 * 0x80); // whitish
                  colored = (red > 0xF0) || ((green > 0xF0) && (blue > 0xF0)); // reddish or yellowish?
                }
                break;
              case 1:
              case 4:
              case 8:
                {
                  if (0 == in_bits)
                  {
                    in_byte = input_buffer[in_idx++];
                    in_bits = 8;
                  }
                  uint16_t pn = (in_byte >> bitshift) & bitmask;
                  whitish = mono_palette_buffer[pn / 8] & (0x1 << pn % 8);
                  colored = color_palette_buffer[pn / 8] & (0x1 << pn % 8);
                  in_byte <<= depth;
                  in_bits -= depth;
                }
                break;
            }
            if (whitish)
            {
              out_byte |= 0x80 >> col % 8; // not black
              out_color_byte |= 0x80 >> col % 8; // not colored
            }
            else if (colored && with_color)
            {
              out_byte |= 0x80 >> col % 8; // not black
            }
            else
            {
              out_color_byte |= 0x80 >> col % 8; // not colored
            }
            if (7 == col % 8)
            {
              output_row_color_buffer[out_idx] = out_color_byte;
              output_row_mono_buffer[out_idx++] = out_byte;
              out_byte = 0;
              out_color_byte = 0;
            }
          } // end pixel
          int16_t yrow = y + (flip ? h - row - 1 : row);
          display.writeImage(output_row_mono_buffer, output_row_color_buffer, x, yrow, w, 1);
        } // end line
        Serial.print("  downloaded in "); Serial.print(millis() - startTime); Serial.println(" ms");
        Serial.print("  bytes read "); Serial.println(bytes_read);
        display.refresh(true);
        display.setRotation(3);
      }
    }
  }
  if (!valid)
  {
    Serial.println("bitmap format not handled.");
  }
}
