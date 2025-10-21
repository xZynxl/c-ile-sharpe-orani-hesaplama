// Gerekli kütüphaneyi programa dahil ediyoruz.
// stdio.h: Standart Girdi/Çýktý fonksiyonlarý için (printf, scanf gibi)
#include <stdio.h>
#include <stdlib.h> // Hata durumunda programdan çýkmak için eklendi (return 1;)

// --- ANA PROGRAM BAÞLANGICI ---
int main() {
    
    // Tüm finansal verilerimizi ondalýklý olabileceði için 'double' tipinde tanýmlýyoruz.
    // 'double', 'float' tipine göre daha yüksek hassasiyet sunar.
    double yatirim_getirisi;
    double risksiz_faiz_orani;
    double standart_sapma;
    double sharpe_orani;

    printf("--- Sharpe Orani Hesaplama Programi ---\n");
    printf("Lutfen degerleri yuzde (%) isareti olmadan girin (orn: 15, 5, 12)\n\n");

    // 1. GÝRDÝ: YATIRIM GETÝRÝSÝ
    printf("1. Yatirim Getirisi (orn: 15): ");
    // Kullanýcýdan double tipinde bir veri almak için scanf'te "%lf" belirtecini kullanýyoruz.
    // '&' iþareti, girilen deðerin hangi deðiþkenin hafýza adresine yazýlacaðýný belirtir.
    if (scanf("%lf", &yatirim_getirisi) != 1) {
        printf("HATA: Gecersiz girdi.\n");
        return 1;
    }

    // 2. GÝRDÝ: RÝSKSÝZ FAÝZ ORANI
    printf("2. Risksiz Faiz Orani (orn: 5): ");
    if (scanf("%lf", &risksiz_faiz_orani) != 1) {
        printf("HATA: Gecersiz girdi.\n");
        return 1;
    }

    // 3. GÝRDÝ: STANDART SAPMA
    printf("3. Standart Sapma (Portfoy Riski) (orn: 12): ");
    if (scanf("%lf", &standart_sapma) != 1) {
        printf("HATA: Gecersiz girdi.\n");
        return 1;
    }

    // --- KRÝTÝK KONTROL ---
    // Formülde standart sapma paydada yer alýr. 
    // Matematikte bir sayýyý sýfýra bölmek tanýmsýzdýr (ve programý çökertir).
    // Bu yüzden standart sapmanýn 0 olup olmadýðýný kontrol etmeliyiz.
    if (standart_sapma == 0) {
        printf("\nHATA: Standart Sapma (payda) 0 olamaz. Hesaplama yapilamiyor.\n");
        return 1; // Programý bir hata koduyla sonlandýr.
    }

    // --- HESAPLAMA ---
    // Hocanýn verdiði formülü uyguluyoruz.
    sharpe_orani = (yatirim_getirisi - risksiz_faiz_orani) / standart_sapma;

    // --- SONUÇLARI YAZDIRMA ---
    printf("\n--- Hesaplama Sonucu ---\n");
    // "%.2f" belirteci, ondalýklý sayýyý virgülden sonra 2 basamak gösterecek þekilde formatlar
    // Týpký örnekteki 0.83 gibi.
    printf("Hesaplanan Sharpe Orani: %.2f\n", sharpe_orani);

    // --- YORUMLAMA (BONUS) ---
    // Hocanýn verdiði kriterlere göre oraný yorumluyoruz.
    if (sharpe_orani >= 3) {
        printf("Degerlendirme: Mukemmel (3 ve uzeri)\n");
    } else if (sharpe_orani >= 2) {
        printf("Degerlendirme: Cok Iyi (2 - 2.99 arasi)\n");
    } else if (sharpe_orani >= 1) {
        printf("Degerlendirme: Iyi (1 - 1.99 arasi)\n");
    } else {
        printf("Degerlendirme: Yeterince iyi degil (1'in altinda)\n");
    }

    // main fonksiyonu baþarýlý bir þekilde bittiðinde 0 döndürür.
    return 0;
}
