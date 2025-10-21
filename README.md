# C Dili ile Sharpe Oranı Hesaplama

Bu proje, Algoritma ve Programlama dersi kapsamında, finansal piyasalarda kullanılan Sharpe (Şarp) Oranı'nı hesaplamak için C dili ile geliştirilmiştir.

## Projenin Amacı

Program, kullanıcıdan aldığı üç temel finansal veriyi (yatırım getirisi, risksiz faiz oranı, standart sapma) kullanarak, yatırımın risk-getiri performansını ölçen Sharpe Oranını hesaplar.

`Şarp Oranı = (Yatırım Getirisi - Risksiz Faiz Oranı) / Standart Sapma`

Program ayrıca hesaplanan oranı, genel geçer finansal standartlara göre (İyi, Çok İyi, Mükemmel) sınıflandırır.

## Nicel Analiz (Quantitative Analysis) Nedir?

Bu proje, **Nicel Analiz (Kantitatif Analiz)** konusuna bir giriş niteliğindedir.

Hocamızın belirttiği gibi: **Kantitatif analiz**, yatırım kararlarını bilgilendirmek için veri ve matematiksel tekniklerin kullanılmasına odaklanan bir finansal analiz dalıdır. Bu analiz türü, finansal modeller oluşturmak, piyasa trendlerini tahmin etmek ve riskleri ölçmek için istatistiksel yöntemlere ve programlamaya dayanır. Sharpe Oranı, bu alanda kullanılan yüzlerce formülden sadece bir tanesidir.

## Nasıl Derlenir ve Çalıştırılır?

1.  Bu repoyu klonlayın veya `main.c` dosyasını indirin.
2.  Bir C derleyicisi (örn: GCC) kullanarak programı derleyin:
    ```bash
    gcc main.c -o sharpe_hesaplayici
    ```
3.  Programı çalıştırın:
    ```bash
    ./sharpe_hesaplayici
    ```

## Kullanılan Teknolojiler ve Konseptler

* **Programlama Dili:** C
* **Temel Konseptler:** `double` veri tipi, `printf` ile formatlı çıktı (`%.2f`), `scanf` ile girdi alma (`%lf`), `if-else if-else` ile koşullu mantık, sıfıra bölme hatası kontrolü.

---
**Geliştirme Notu:** Bu projenin planlama ve dokümantasyon sürecinde Google Gemini yapay zeka modelinden destek alınmıştır.
