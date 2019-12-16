/*
  template.h
  
*/

void imageFromUrl(String url, int16_t x, int16_t y, String fingerprint = "", bool with_color = true);

void drawBarcode39(int x, int y, int width, int height, int pitch, String barcode){
  int c = 0;
  display.fillRect(x, y, width, height, GxEPD_WHITE);
  c = (pitch * 10);

  for(int i = 0; i < barcode.length(); i++){
     String binCode = getBinCode(barcode.charAt(i));
     bool bk = true;
     for(int j = 0; j < 9; j++){
      int color;
      if(bk){
        color = GxEPD_BLACK; 
      }else{
        color = GxEPD_WHITE;
      }
      bk = !bk;
      int bw;
      if(binCode.charAt(j) == '0'){
        bw = pitch;
      }else{
        bw = pitch * 2;
      }
      display.fillRect( c, y, bw, height, color);
      c = c + bw;
     }
     //Gap
     display.fillRect( c, y, pitch, height, GxEPD_WHITE);
     c = c + pitch;
  }
  
}

void drawIcon64(int x, int y, String icon, long color){
  
  if (icon == "01d" || icon == "01n") { display.drawInvertedBitmap(x, y, weather01, 64, 64, color); return; }
  if (icon == "02d" || icon == "02n") { display.drawInvertedBitmap(x, y, weather02, 64, 64, color); return; }
  if (icon == "03d" || icon == "03n") { display.drawInvertedBitmap(x, y, weather03, 64, 64, color); return; }
  if (icon == "04d" || icon == "04n") { display.drawInvertedBitmap(x, y, weather04, 64, 64, color); return; }
  if (icon == "09d" || icon == "09n") { display.drawInvertedBitmap(x, y, weather09, 64, 64, color); return; }
  if (icon == "10d" || icon == "10n") { display.drawInvertedBitmap(x, y, weather10, 64, 64, color); return; }
  if (icon == "11d" || icon == "11n") { display.drawInvertedBitmap(x, y, weather11, 64, 64, color); return; }
  if (icon == "13d" || icon == "13n") { display.drawInvertedBitmap(x, y, weather13, 64, 64, color); return; }
  if (icon == "50d" || icon == "50n") { display.drawInvertedBitmap(x, y, weather50, 64, 64, color); return; }
  if (icon == "twitter") { display.drawInvertedBitmap(x, y, twitter64, 64, 64, color); return; }
  if (icon == "mail") { display.drawInvertedBitmap(x, y, mail64, 64, 64, color); return; } 
  if (icon == "fail") { display.drawInvertedBitmap(x, y, fail64, 64, 64, color); return; }   
  if (icon == "ace") { display.drawInvertedBitmap(x, y, ace64, 64, 64, color); return; } 
  if (icon == "duke") { display.drawInvertedBitmap(x, y, duke64, 64, 64, color); return; }  
  if (icon == "oracle") { display.drawInvertedBitmap(x, y, oracle64, 64, 64, color); return; } 
  if (icon == "champion") { display.drawInvertedBitmap(x, y, champion64, 64, 64, color); return; } 
  if (icon == "jduchess") { display.drawInvertedBitmap(x, y, jduchess64, 64, 64, color); return; } 

  if (icon == "db") { display.drawInvertedBitmap(x, y, db64, 64, 64, color); return; }
  if (icon == "java") { display.drawInvertedBitmap(x, y, java64, 64, 64, color); return; } 
  if (icon == "containers") { display.drawInvertedBitmap(x, y, containers64, 64, 64, color); return; }   
  if (icon == "microservices") { display.drawInvertedBitmap(x, y, microservices64, 64, 64, color); return; } 
  if (icon == "opensource") { display.drawInvertedBitmap(x, y, opensource64, 64, 64, color); return; }  
  if (icon == "chatbots") { display.drawInvertedBitmap(x, y, chatbots64, 64, 64, color); return; } 
  if (icon == "blockchain") { display.drawInvertedBitmap(x, y, blockchain64, 64, 64, color); return; }   
  if (icon == "javascript") { display.drawInvertedBitmap(x, y, javascript64, 64, 64, color); return; }  
  if (icon == "nighthacker") { display.drawInvertedBitmap(x, y, nighthacker64, 64, 64, color); return; }   
  if (icon == "wifi") { display.drawInvertedBitmap(x, y, wifi64, 64, 64, color); return; } 
}

void drawIcon128(int x, int y, String icon, long color){
  if (icon == "oracle") { display.drawInvertedBitmap(x, y, oracle128, 128, 128, color); return; }
  if (icon == "champion") { display.drawInvertedBitmap(x, y, champion128, 128, 128, color); return; }  
  if (icon == "jduchess") { display.drawInvertedBitmap(x, y, jduchess128, 128, 128, color); return; }  

  if (icon == "db") { display.drawInvertedBitmap(x, y, db128, 128, 128, color); return; }
  if (icon == "java") { display.drawInvertedBitmap(x, y, java128, 128, 128, color); return; } 
  if (icon == "containers") { display.drawInvertedBitmap(x, y, containers128, 128, 128, color); return; }   
  if (icon == "microservices") { display.drawInvertedBitmap(x, y, microservices128, 128, 128, color); return; } 
  if (icon == "opensource") { display.drawInvertedBitmap(x, y, opensource128, 128, 128, color); return; }  
  if (icon == "chatbots") { display.drawInvertedBitmap(x, y, chatbots128, 128, 128, color); return; } 
  if (icon == "blockchain") { display.drawInvertedBitmap(x, y, blockchain128, 128, 128, color); return; }   
  if (icon == "javascript") { display.drawInvertedBitmap(x, y, javascript128, 128, 128, color); return; } 
  if (icon == "nighthacker") { display.drawInvertedBitmap(x, y, nighthacker128, 128, 128, color); return; } 
  if (icon == "wifi") { display.drawInvertedBitmap(x, y, wifi128, 128, 128, color); return; } 
}

void drawBackground(int x, int y, String backgroundImage, long color){ 
  if (backgroundImage == "codeone") { display.drawInvertedBitmap(x, y, codeone264, display.width(), display.height(), color); return; } 
  if (backgroundImage == "oracle") { display.drawInvertedBitmap(x, y, oracle264, display.width(), display.height(), color); return; } 
  
}

void drawBadge(int x, int y, int radius, String badge, long color) {
    int circleColor = GxEPD_BLACK;
    int badgeText = GxEPD_WHITE;

    if (color == GxEPD_BLACK) {
      circleColor = GxEPD_WHITE;
      badgeText = GxEPD_BLACK;
    }
  
    //int radius = 32;
    bool isDegree = false;
    if (badge.indexOf("u00B0") > -1 ){
      badge.replace("u00B0", "");
      isDegree = true;
    }
    display.fillCircle(x + radius, y + radius, radius - 2, circleColor);
    display.setTextColor(badgeText);
    if (badge.length() > 1 && badge.length() < 3) {
      // Two characters
      display.setFont(&FreeMonoBold18pt7b);
      display.setCursor(x  + 11, y + 42); 
    } else if (badge.length() == 1 ) {
      // One character
      display.setFont(&FreeMonoBold18pt7b);  
      display.setCursor(x + 21, y + 44);
    } else if (badge.length() > 2 ) {
      // Three characters
      display.setFont(&FreeMonoBold12pt7b);  
      display.setCursor(x + 11, y + 40);
    }
    display.print(badge);

    if (isDegree == true) {
      display.setFont(&TomThumb);
      display.setTextSize(2);
      //display.setCursor(x + radius + radius / 2 + 5, y + radius - radius / 3 + 5);
      display.setCursor(x + radius + radius / 2, y + radius - radius / 3);
      display.print("o");
    }

    display.setTextSize(1);
    display.setTextColor(circleColor);
 

}


void template1(String title, String subtitle, String body, String icon, String badge, String backgroundColor, String fingerprint) {
  long bgColor = GxEPD_WHITE;
  long txtColor = GxEPD_BLACK;
  
  display.setFullWindow();
  display.firstPage();

  if (backgroundColor == "black"){
    bgColor = GxEPD_BLACK;
    txtColor = GxEPD_WHITE;
  } 
  
  do {
    display.fillScreen(bgColor);
    display.setTextColor(txtColor);  

    if (badge != "") {
      drawBadge(0, 0, 32, badge, bgColor);  
    } else if (icon != "" && icon.indexOf("http") == -1 && badge == "") {
      drawIcon64(0, 0, icon, txtColor);
    }
    
    // title
    display.setFont(&FreeSansBold12pt7b);  
    display.setCursor(72, 25);
    display.println(title.substring(0, 16));  
  
      // subtitle 
    display.setFont(&FreeSans9pt7b);
    display.setCursor(73, 45);
    display.println(subtitle.substring(0, 20));
  
    // body
    display.setFont(&FreeSans9pt7b);
    display.setCursor(0, 80);
    display.println(body.substring(0, 170));
    
  }
  while (display.nextPage());

  if (icon != "" && icon.indexOf("http") > -1 && badge == ""){
    imageFromUrl(icon, 0, 0, fingerprint , false);
  } else {
    Serial.println("template1 - no image required");
  }
    
}

void template2(String title, String subtitle, String body, String icon, String badge, String backgroundColor, String fingerprint) {
  long bgColor = GxEPD_WHITE;
  long txtColor = GxEPD_BLACK;
  
  display.setFullWindow();
  display.firstPage();

  if (backgroundColor == "black"){
    bgColor = GxEPD_BLACK;
    txtColor = GxEPD_WHITE;
  } 

  int middle = display.width() / 2 - 38;
  
  do {
    display.fillScreen(bgColor);
    display.setTextColor(txtColor);  
  
    if (badge != "") {
      // badge
      drawBadge(middle, 40, 32, badge, bgColor); 
    } else if (icon != "" && icon.indexOf("http") == -1 && badge == "") {
      // icon
      drawIcon64(middle, 42, icon, txtColor);   
    }

    
    // title
    display.setFont(&FreeSansBold12pt7b);  
    display.setCursor(0, 20);
    display.println(title.substring(0, 22));  
  
    // subtitle 
    display.setFont(&FreeSans9pt7b);
    display.setCursor(0, 38);
    display.println(subtitle.substring(0, 26));
    
    // body 
    display.setFont(&FreeSans9pt7b);
    display.setCursor(0, 125);
    display.println(body.substring(0, 105)); 
    
  }
  while (display.nextPage());

  if (icon != "" && icon.indexOf("http") > -1 && badge == ""){
    int iconX = display.height() / 2 - 42;
    int iconY = display.width() / 2 - 38;
    imageFromUrl(icon, iconX, -iconY, fingerprint , false);
  }
    
}

void template3(String title, String subtitle, String body, String icon, String badge, String backgroundColor, String fingerprint) {
  long bgColor = GxEPD_WHITE;
  long txtColor = GxEPD_BLACK;
  
  display.setFullWindow();
  display.firstPage();

  if (backgroundColor == "black"){
    bgColor = GxEPD_BLACK;
    txtColor = GxEPD_WHITE;
  } 
  
  do {
    display.fillScreen(bgColor);
    display.setTextColor(txtColor);  

    if (badge != "") {
      drawBadge(display.width() - 68, 0, 32, badge, bgColor);  
    } else if (icon != "" && icon.indexOf("http") == -1 && badge == "") {
      drawIcon64(display.width() - 68, 0, icon, txtColor);
    }
    
    // title
    display.setFont(&FreeSansBold12pt7b);  
    display.setCursor(0, 25);
    display.println(title.substring(0, 16));  
  
      // subtitle 
    display.setFont(&FreeSansBold9pt7b);
    display.setCursor(1, 43);
    display.println(subtitle.substring(0, 24));
  
    // body
    display.setFont(&FreeSans9pt7b);
    display.setCursor(0, 70);
    display.println(body.substring(0, 170));
    
  }
  while (display.nextPage());

  if (icon != "" && icon.indexOf("http") > -1 && badge == ""){
    imageFromUrl(icon, 100, 0, fingerprint , false);
  }
    
}

void template4(String title, String subtitle, String body, String icon, String badge, String backgroundColor, String fingerprint) {
  long bgColor = GxEPD_WHITE;
  long txtColor = GxEPD_BLACK;
  
  display.setFullWindow();
  display.firstPage();

  if (backgroundColor == "black"){
    bgColor = GxEPD_BLACK;
    txtColor = GxEPD_WHITE;
  } 
  
  do {
    display.fillScreen(bgColor);
    display.setTextColor(txtColor);  

    if (badge != "") {
      drawBadge(display.width() - 68,  32, display.height() - 68, badge, bgColor);  
    } else if (icon != "" && icon.indexOf("http") == -1 && badge == "") {
      drawIcon64(display.width() - 68, display.height() - 68, icon, txtColor);
    }
    
    // title
    display.setFont(&FreeSansBold12pt7b);  
    display.setCursor(0, 25);
    display.println(title.substring(0, 20));  
  
      // subtitle 
    display.setFont(&FreeSans9pt7b);
    display.setCursor(0, 43);
    display.println(subtitle.substring(0, 32));
  
    // body
    display.setFont(&FreeSans9pt7b);
    display.setCursor(0, 70);
    display.println(body.substring(0, 170));
    
  }
  while (display.nextPage());

  if (icon != "" && icon.indexOf("http") > -1 && badge == ""){
    imageFromUrl(icon, display.height() - 64, -display.width() + 64, fingerprint , false);
  }
    
}

void template5(String title, String subtitle, String body, String backgroundColor) {
  long bgColor = GxEPD_WHITE;
  long txtColor = GxEPD_BLACK;
  
  display.setFullWindow();
  display.firstPage();

  if (backgroundColor == "black"){
    bgColor = GxEPD_BLACK;
    txtColor = GxEPD_WHITE;
  } 
  
  do {
    display.fillScreen(bgColor);
    display.setTextColor(txtColor);  
    
    // title
    display.setFont(&FreeSansBold18pt7b);
    if (subtitle.length() > 15) { subtitle = subtitle.substring(0, 15); }  
    int xTitle = display.width() / 2 - title.length() / 2 * 18;
    display.setCursor(xTitle - 10, 25);
    display.println(title);  
  
      // subtitle 
    display.setFont(&FreeSansBold9pt7b);
    if (subtitle.length() > 25) { subtitle = subtitle.substring(0, 25); }  
    int xSubtitle = display.width() / 2 - subtitle.length() / 2 * 9;    
    display.setCursor(xSubtitle - 12 , 45);
    display.println(subtitle);
  
    // body
    display.setFont(&FreeSans9pt7b);
    display.setCursor(0, 72);
    display.println(body.substring(0, 170));
    
  }
  while (display.nextPage());
    
}

void template6(String title, String subtitle, String body, String backgroundColor) {
  long bgColor = GxEPD_WHITE;
  long txtColor = GxEPD_BLACK;
  
  display.setFullWindow();
  display.firstPage();

  if (backgroundColor == "black"){
    bgColor = GxEPD_BLACK;
    txtColor = GxEPD_WHITE;
  } 
  
  do {
    display.fillScreen(bgColor);
    display.setTextColor(txtColor);  
    
    // title
    display.setFont(&FreeSansBold18pt7b);
    if (subtitle.length() > 15) { subtitle = subtitle.substring(0, 15); }  
    int xTitle = display.width() / 2 - title.length() / 2 * 18;
    display.setCursor(xTitle - 10, 80);
    display.println(title);  
  
      // subtitle 
    display.setFont(&FreeSansBold9pt7b);
    if (subtitle.length() > 25) { subtitle = subtitle.substring(0, 25); }  
    int xSubtitle = display.width() / 2 - subtitle.length() / 2 * 9;    
    display.setCursor(xSubtitle - 12 , 100);
    display.println(subtitle);
  
    // body
    display.setFont(&FreeSans9pt7b);
    display.setCursor(1, 146);
    display.println(body.substring(0, 80));
    
  }
  while (display.nextPage());
    
}

// Minimalist - No Icon
void template7(String title, String subtitle, String backgroundColor, String backgroundImage, String fingerprint){

  long bgColor = GxEPD_BLACK;
  long txtColor = GxEPD_WHITE;

  if (backgroundColor == "white"){
    bgColor = GxEPD_WHITE;
    txtColor = GxEPD_BLACK;
  } 

  if (backgroundImage == "") { backgroundImage = "oracle";} 

  display.setFullWindow();
  display.firstPage();
  
  do {
    if (backgroundImage.indexOf("http") == -1){
      display.fillScreen(txtColor);
      drawBackground(0, 0, backgroundImage, bgColor);
    }
    else {
      imageFromUrl(backgroundImage, 0, 0, fingerprint , false);
    }
  
    display.setTextColor(txtColor);
    
    // title
    display.setFont(&FreeSansBold12pt7b);  
    display.setCursor(0, 20);
    display.println(title.substring(0, 22));  
    
    // subtitle 
    display.setFont(&FreeSans9pt7b);
    if (subtitle.length() > 105) { subtitle = subtitle.substring(0, 105); }
    int x = display.width() / 2 - subtitle.length() / 2 * 9;
    display.setCursor(x, display.height() - 15);
    display.println(subtitle); 
    
  }
  while (display.nextPage());

  // WAM - seems this overwrites text ...
  //if (backgroundImage.indexOf("http") > -1){
  //  imageFromUrl(backgroundImage, 0, 0, fingerprint , false);
  //}

}

// Minimalist - No Icon
void template8(String backgroundColor, String backgroundImage, String fingerprint){

  long bgColor = GxEPD_BLACK;
  long txtColor = GxEPD_WHITE;

  if (backgroundColor == "white"){
    bgColor = GxEPD_WHITE;
    txtColor = GxEPD_BLACK;
  } 

  if (backgroundColor == "white"){ bgColor = GxEPD_WHITE; } 
  if (backgroundImage == "") { backgroundImage = "oracle";}  

  display.setFullWindow();
  display.firstPage();
  do {
    if (backgroundImage.indexOf("http") == -1){
      display.fillScreen(txtColor);
      drawBackground(0, 0, backgroundImage, bgColor);
    }
  }
  while (display.nextPage());
  
  if (backgroundImage.indexOf("http") > -1){
    imageFromUrl(backgroundImage, 0, 0, fingerprint , false);
  }
  
}

// status
void template9(String title, String subtitle, String backgroundColor){
  long bgColor = GxEPD_BLACK;
  long txtColor = GxEPD_WHITE;

  if (backgroundColor == "white"){
    bgColor = GxEPD_WHITE;
    txtColor = GxEPD_BLACK;
  } 
  
  display.setFullWindow();
  //display.setPartialWindow(0, 0, display.width(), display.height());
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);

    display.setFont(&FreeSansBold9pt7b);
    display.setCursor(25, 80);
    display.println(title.substring(0,50));
    
    display.setFont(&FreeMono9pt7b);
    display.setCursor(25, 100);
    display.println(subtitle.substring(0,50));
  }
  while (display.nextPage());
}


// barcode template 43 max chars
void template10(String title, String subtitle, String body, String backgroundColor, String barcode){
  long bgColor = GxEPD_BLACK;
  long txtColor = GxEPD_WHITE;

  if (backgroundColor == "white"){
    bgColor = GxEPD_WHITE;
    txtColor = GxEPD_BLACK;
  } 

  display.setFullWindow();
  display.firstPage();

  do {
    display.fillScreen(bgColor);
    display.setTextColor(txtColor);
  
    display.setFont(&FreeSansBold18pt7b);
    display.setCursor(0, 30);
    display.println(title.substring(0,15));
    
    display.setFont(&FreeSansBold9pt7b);
    display.setCursor(1, 50);
    display.println(subtitle.substring(0,26));

    display.setFont(&FreeSans9pt7b);
    display.setCursor(0, 77);
    display.println(body.substring(0,65));
  
    String formattedBarcode = String("@" + barcode + "#");
    drawBarcode39(50, 110, display.width(), 50, 1.9, formattedBarcode);

    display.setFont(&FreeMono9pt7b);
    int barcodeX = display.width() / 2 - barcode.length() / 2 * 5;
    display.setCursor(12, 172);
    display.println(barcode);
  

  }
  while (display.nextPage());

}

void template11(String title, String subtitle, String icon, String badge, String backgroundColor, String fingerprint) {
  long bgColor = GxEPD_WHITE;
  long txtColor = GxEPD_BLACK;
  int iconSize = 128;
  
  display.setFullWindow();
  display.firstPage();

  if (backgroundColor == "black"){
    bgColor = GxEPD_BLACK;
    txtColor = GxEPD_WHITE;
  } 

  int middle = display.width() / 2 - 68;
  
  do {
    display.fillScreen(bgColor);
    display.setTextColor(txtColor);  
  
    if (badge != "") {
      // badge
      drawBadge(middle, 2, 64, badge, bgColor); 
    } else if (icon != "" && icon.indexOf("http") == -1 && badge == "") {
      // icon
      drawIcon128(middle, 2, icon, txtColor);   
    }
    
    // title
    display.setFont(&FreeSansBold12pt7b); 
    int titleX = 126 - (title.length() / 2 * 12);
    display.setCursor(titleX, 150);
    display.println(title.substring(0, 22));  
  
    // subtitle 
    display.setFont(&FreeSans9pt7b);
    int subtitleX = 126 - (subtitle.length() / 2 * 9);
    display.setCursor(subtitleX, 170);
    display.println(subtitle.substring(0, 26));
  }
  while (display.nextPage());

  if (icon != "" && icon.indexOf("http") > -1 && badge == ""){
    int iconX = display.height() / 2 - 64;
    int iconY = display.width() / 2 - 68;
    imageFromUrl(icon, 2, -iconY, fingerprint , false);
    
  }
    
}

void custom(){
  
}

void defaultScreen(){
  String mac = WiFi.macAddress();
  mac.replace(":", "");
  mac.toUpperCase();
  
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.drawInvertedBitmap(0, 0, oracle264, display.width(), display.height(), GxEPD_BLACK);
  }
  while (display.nextPage());    
  template10(projectName, projectAuthor, projectSite, "white", mac);
}
