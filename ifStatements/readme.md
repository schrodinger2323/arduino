# Arduino Tutorial 13: Understanding Arduino If Statements

Ödev: potansiyometreden okuduğumuz voltaj değeri(x):

x<3 ise Green LED yak diğerlerini söndür

x>3 ve x<4 ise Yellow LED yak diğerlerini söndür

x>4 ise Red LED yak diğerlerini söndür.

kullandığımız malzemeler: 

-arduino uno kartı

-breadboard

-3 tane led: kırmızı, sarı, yeşil

-3 tane 330ohm direnç

-potansiyometre

-jumper kablolar

devre şeması şu şekildedir: 

![WhatsApp Image 2025-02-06 at 16 36 59](https://github.com/user-attachments/assets/d9793d93-0700-420a-9aba-879b04be91ad)

devrenin gerçeklenmiş hali:

![WhatsApp Image 2025-02-06 at 16 42 14](https://github.com/user-attachments/assets/df0c287a-f4a6-4f31-b469-408228d96a30)

pot.un ayar kolunu saat yönünde çevirirsek voltaj değeri 0Va yaklaşıyor

saat yönünün tersine çevirirsek değerler 5Va yaklaşıyor.


------------Kod açıklamaları------------

-kod içerisinde kullandığımız değişkenleri tanımlarız:

readVal: potansiyometrenin (pot) B bacağına bağladığımız analog pininden(A2) okuduğumuz değerleri tutmak içindir.

V2:  gerçek voltaj değerlerini tutmak içindir. ara değerler de lazım olduğu için float olarak tanımlarız.

rLed, yLed, gLed: kırmızı, sarı ve yeşil ledlerin arduino uno kartında bağlı olduğu dijital pinlerdir. bu pin numaralarını direkt olarak da kullabiliriz fakat sayıları bir değişkende depolamak kodun okunabilirliğini artırır aynı zamanda bakımını ve güncellemesini kolaylaştırır.

![Ekran görüntüsü 2025-02-06 163842](https://github.com/user-attachments/assets/02caca25-0d18-4367-8e97-9687729bdc96)


-voltaj değerlerini serial monitorde izlemek için 9600 baud rate ile başlattık:

![Ekran görüntüsü 2025-02-06 163854](https://github.com/user-attachments/assets/c48ea8f6-9aa0-45a4-9df8-9ae0d7e55a29)


-arduino pinleri varsayılan olarak INPUT'tur. bu durumdayken pinler yüksek empedans modundadır. o yuzden eğer bir pini input olarak kullanacaksak belirtmemize gerek yok tekrardan..
  ////pinMode(A2, INPUT);
  
fakat bir pini OUTPUT olarak kullanacaksak bunu set etmemiz gerek. çünkü düşük empedans halindeyken pinler dışarıdan gelen sinyale karşı çok hassatır.. belirsiz bir voltaj durumu oluşur eğer output ayarlamazsak(float state).
nitekim output olarak ayarlamadığımızda ledlerimiz sönük bir şekilde yanar..
düşük empedans pini(output) ise güçlü davranır ve dış devreye kararlı şekilde 0V/5V gönderebilir. 3 ledimizi de output olarak ayarladık:

![Ekran görüntüsü 2025-02-06 163905](https://github.com/user-attachments/assets/6ab97e65-b492-4eb3-a3ce-132fa3f1b90f)


-pot.un B bacağına bağlı analog A2 pinini okuruz. bu değer tam sayı tipinde [0,2^10) aralığındadır.
gerçek voltaj değerlerine yani [0V,5V] aralığına dönüştürmek için ölçekleme yapıyoruz.

gerçek voltaj değeri=(5./1023.)*analog pinden okunan değer;

bu formül yerine map() fonksiyonunu da kullanabiliriz. fakat map() fonksiyonu doğrudan tam sayılarla çalıştığı için farklı bir yaklaşıma ihtiyaç duyar.
burada değerler mV cinsine çevriliyor ve sonrasında 1000'e bölünerek volt cinsine dönüşüyor : V2 = map(readVal, 0, 1023, 0, 5000)/1000.; 

![Ekran görüntüsü 2025-02-06 163948](https://github.com/user-attachments/assets/40fd6a4a-3037-4888-8322-cbcaf99cc7dd)


-voltaj değerlerini serial monitore bastık: 

![Ekran görüntüsü 2025-02-06 164007](https://github.com/user-attachments/assets/00c8afe0-a4a4-4c46-a2df-8bc5196337b8)


-soruda verilen aralıklara uygun olarak if-else if-else ifadeleri ile kontrol sağlayarak ledlerimizi yakıp söndürdük:

![Ekran görüntüsü 2025-02-06 164042](https://github.com/user-attachments/assets/deacc575-5304-4610-a5d4-d5365a138eec)


değerleri serial monitorde düzgün görebilmemiz için gecikme ekleriz. yoksa çok hızlı.

![Ekran görüntüsü 2025-02-06 170637](https://github.com/user-attachments/assets/48415925-516f-446d-a188-7a07a1672da1)



