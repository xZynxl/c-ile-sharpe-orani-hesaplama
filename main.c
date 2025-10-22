// Gerekli kütüphaneyi programa dahil ediyoruz.
// stdio.h: Standart Girdi/Çıktı fonksiyonları için (printf, scanf gibi)
#include <stdio.h>
#include <stdlib.h> // Hata durumunda programdan çıkmak için eklendi (return 1;)

// --- ANA PROGRAM BAŞLANGICI ---
int main() {
    
    // Tüm finansal verilerimizi ondalıklı olabileceği için 'double' tipinde tanımlıyoruz.
    // 'double', 'float' tipine göre daha yüksek hassasiyet sunar.
    double yatirim_getirisi;
    double risksiz_faiz_orani;
    double standart_sapma;
    double sharpe_orani;

    printf("--- Sharpe Orani Hesaplama Programi ---\n");
    printf("Lutfen degerleri yuzde (%) isareti olmadan girin (orn: 15, 5, 12)\n\n");

    // 1. GİRDİ: YATIRIM GETİRİSİ
    printf("1. Yatirim Getirisi (orn: 15): ");
    // Kullanıcıdan double tipinde bir veri almak için scanf'te "%lf" belirtecini kullanıyoruz.
    // '&' işareti, girilen değerin hangi değişkenin hafıza adresine yazılacağını belirtir.
    if (scanf("%lf", &yatirim_getirisi) != 1) {
        printf("HATA: Gecersiz girdi.\n");
        return 1;
    }

    // 2. GİRDİ: RİSKSİZ FAİZ ORANI
    printf("2. Risksiz Faiz Orani (orn: 5): ");
    if (scanf("%lf", &risksiz_faiz_orani) != 1) {
        printf("HATA: Gecersiz girdi.\n");
        return 1;
    }

    // 3. GİRDİ: STANDART SAPMA
    printf("3. Standart Sapma (Portfoy Riski) (orn: 12): ");
    if (scanf("%lf", &standart_sapma) != 1) {
        printf("HATA: Gecersiz girdi.\n");
        return 1;
    }

    // --- KRİTİK KONTROL ---
    // Formülde standart sapma paydada yer alır. 
    // Matematikte bir sayıyı sıfıra bölmek tanımsızdır (ve programı çökertir).
    // Eğerki ben bu kontrolü yapmasaydım bu program runtime eror verirdi.
    // Bu yüzden standart sapmanın 0 olup olmadığını kontrol etmeliyiz.
    if (standart_sapma == 0) {
        printf("\nHATA: Standart Sapma (payda) 0 olamaz. Hesaplama yapilamiyor.\n");
        return 1; // Programı bir hata koduyla sonlandır.
    }

    // --- HESAPLAMA ---
    sharpe_orani = (yatirim_getirisi - risksiz_faiz_orani) / standart_sapma;

    // --- SONUÇLARI YAZDIRMA ---
    printf("\n--- Hesaplama Sonucu ---\n");
    // "%.2f" belirteci, ondalıklı sayıyı virgülden sonra 2 basamak gösterecek şekilde formatlar
    printf("Hesaplanan Sharpe Orani: %.2f\n", sharpe_orani);

    // --- YORUMLAMA ---
    if (sharpe_orani >= 3) {
        printf("Degerlendirme: Mukemmel (3 ve uzeri)\n");
    } else if (sharpe_orani >= 2) {
        printf("Degerlendirme: Cok Iyi (2 - 2.99 arasi)\n");
    } else if (sharpe_orani >= 1) {
        printf("Degerlendirme: Iyi (1 - 1.99 arasi)\n");
    } else {
        printf("Degerlendirme: Yeterince iyi degil (1'in altinda)\n");
    }

    // main fonksiyonu başarılı bir şekilde bittiğinde 0 döndürür.
    return 0;
}

