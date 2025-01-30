#Arduino Tutorial 10: Understanding How To Read Analog Voltage using analogRead Command

Ödev: farklı değerlerde olan iki direnci seri bağlayarak devre kur. devrenin analizini yap. daha sonra serial monitorde voltaj değerlerinin gerçek değerlerini ve analogRead skalasında denk düşen değerleri izle.

Çözüm: arduino uno kartından 5V aldık. 330 ohm ve 1K olan iki direnci seri bağladık. en son yine uno kartındaki gnd pinine bağladık. böylece devremiz hazır:

![WhatsApp Image 2025-01-30 at 23 15 12](https://github.com/user-attachments/assets/9fc40498-dedf-45f4-a116-ce89a0acc936)

fotoğraftaki sarı kablo uno kartındaki 5V'a, kahverengi kablo karttaki gnd pinine bağlı
kırmızı kablo ise kart üzerinde analog A3 pinine bağladığımız kablodur. bu kabloyu devrenin farklı konumlarına koyarak serial monitorde gördüğümüz değerler aşağıda verilmiştir.

Not: örnek olması açısından 330ohm ve 1K dirençler kullandık fakat istenilen değerde olabilir. 
ayrıca analog okuma yapmak için arduino uno kartı üzerindeki [A0, A5] pinlerinden biri kullanılabilir. biz A3 portunu kullandık.

devre analizini yapınca 5V kaynaktan çıkan akımı yaklaşık olarak 3.75 mA bulduk. V=I.R ohm kanunundan her bir direncin üzerine düşen gerilimi bulduk. daha sonra devrenin farklı noktalarındaki gerilimleri analogRead.ino ve analogRead_with_actualVoltageValue.ino dosyaları için derledik ve serial monitorü izledik.

analogRead.ino -> serial monitorde analogRead skalası olan 0 ile 1023 arasındaki değeri gösterir.

analogRead_with_actualVoltageValue.ino -> analogRead ile aldığımız değeri gerçek voltaj değerine dönüştürdük.. bu gerçek voltaj değerlerini serial monitorde izledik.

![WhatsApp Image 2025-01-30 at 23 18 02](https://github.com/user-attachments/assets/61fc809a-8742-4ab8-a3f0-a3b043ad06fa)


NOT: analogRead den okuduğumuz değerleri gerçek voltaj değerlerine dönüştürmek için kullandığımız formül: 

![WhatsApp Image 2025-01-30 at 23 18 37](https://github.com/user-attachments/assets/44b8e3e0-dca9-4c97-abf9-d73e573dc7ec)


![WhatsApp Image 2025-01-30 at 23 36 28](https://github.com/user-attachments/assets/c0fa4db5-8fd5-494f-ba64-6f0eedcc8042)

A3 analog pinini kırmızı kablo ile *a, *b ve *c konumlarına bağladığımızda serial monitorde izlediğimiz gerçek voltaj değerleri ve analogRead skalasındaki değerler(0-1023) şunlardır:

*a konumunda:

devre:

![WhatsApp Image 2025-01-30 at 23 41 12](https://github.com/user-attachments/assets/1c2198b8-9f6b-4d25-a518-91e832a300be)

(analogRead.ino) 

![Ekran görüntüsü 2025-01-30 224350](https://github.com/user-attachments/assets/f1c85ad7-59dd-4a67-b2e3-fa52224c4a88)

(analogRead_with_actualVoltageValue.ino)

![Ekran görüntüsü 2025-01-30 223513](https://github.com/user-attachments/assets/3ba7bcd7-7512-4f73-ac62-515168ff48df)

*b konumunda: (burada R2 direncinin yani 1K ohmluk direncin üzerine düşen gerilim ölçülmüş olur. devre analizi yaptığımızda bu değer yaklaşık 3.75V idi. elemanların devreye tam bağlanmamış olması gibi ihtimaller nedeniyle serial monitorde tam olarak bu değeri göremedik. fakat aşağı yukarı aynı.)

devre: 

![WhatsApp Image 2025-01-30 at 23 44 44](https://github.com/user-attachments/assets/e5b6b7ed-bcbe-4170-8cf6-3b07df5318b5)

(analogRead.ino) 

![Ekran görüntüsü 2025-01-30 224315](https://github.com/user-attachments/assets/8f3f766a-07db-44cc-9a44-b04fdb8687d8)

(analogRead_with_actualVoltageValue.ino)

![Ekran görüntüsü 2025-01-30 223928](https://github.com/user-attachments/assets/98495c4e-1cc7-49f6-aa86-b304c32d5caf)

*c konumunda: 

devre:

![WhatsApp Image 2025-01-30 at 23 50 12](https://github.com/user-attachments/assets/4aeac97d-1292-4ba1-ad79-c86c8571d0e2)

(analogRead.ino) 

![Ekran görüntüsü 2025-01-30 224049](https://github.com/user-attachments/assets/d51aae34-bd22-497b-87a9-00f5db4218b5)

(analogRead_with_actualVoltageValue.ino)

![Ekran görüntüsü 2025-01-30 223452](https://github.com/user-attachments/assets/31f463de-93d4-44d9-9814-9da7772759fd)







