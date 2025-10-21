// Gerekli k�t�phaneyi programa dahil ediyoruz.
// stdio.h: Standart Girdi/��kt� fonksiyonlar� i�in (printf, scanf gibi)
#include <stdio.h>
#include <stdlib.h> // Hata durumunda programdan ��kmak i�in eklendi (return 1;)

// --- ANA PROGRAM BA�LANGICI ---
int main() {
    
    // T�m finansal verilerimizi ondal�kl� olabilece�i i�in 'double' tipinde tan�ml�yoruz.
    // 'double', 'float' tipine g�re daha y�ksek hassasiyet sunar.
    double yatirim_getirisi;
    double risksiz_faiz_orani;
    double standart_sapma;
    double sharpe_orani;

    printf("--- Sharpe Orani Hesaplama Programi ---\n");
    printf("Lutfen degerleri yuzde (%) isareti olmadan girin (orn: 15, 5, 12)\n\n");

    // 1. G�RD�: YATIRIM GET�R�S�
    printf("1. Yatirim Getirisi (orn: 15): ");
    // Kullan�c�dan double tipinde bir veri almak i�in scanf'te "%lf" belirtecini kullan�yoruz.
    // '&' i�areti, girilen de�erin hangi de�i�kenin haf�za adresine yaz�laca��n� belirtir.
    if (scanf("%lf", &yatirim_getirisi) != 1) {
        printf("HATA: Gecersiz girdi.\n");
        return 1;
    }

    // 2. G�RD�: R�SKS�Z FA�Z ORANI
    printf("2. Risksiz Faiz Orani (orn: 5): ");
    if (scanf("%lf", &risksiz_faiz_orani) != 1) {
        printf("HATA: Gecersiz girdi.\n");
        return 1;
    }

    // 3. G�RD�: STANDART SAPMA
    printf("3. Standart Sapma (Portfoy Riski) (orn: 12): ");
    if (scanf("%lf", &standart_sapma) != 1) {
        printf("HATA: Gecersiz girdi.\n");
        return 1;
    }

    // --- KR�T�K KONTROL ---
    // Form�lde standart sapma paydada yer al�r. 
    // Matematikte bir say�y� s�f�ra b�lmek tan�ms�zd�r (ve program� ��kertir).
    // Bu y�zden standart sapman�n 0 olup olmad���n� kontrol etmeliyiz.
    if (standart_sapma == 0) {
        printf("\nHATA: Standart Sapma (payda) 0 olamaz. Hesaplama yapilamiyor.\n");
        return 1; // Program� bir hata koduyla sonland�r.
    }

    // --- HESAPLAMA ---
    // Hocan�n verdi�i form�l� uyguluyoruz.
    sharpe_orani = (yatirim_getirisi - risksiz_faiz_orani) / standart_sapma;

    // --- SONU�LARI YAZDIRMA ---
    printf("\n--- Hesaplama Sonucu ---\n");
    // "%.2f" belirteci, ondal�kl� say�y� virg�lden sonra 2 basamak g�sterecek �ekilde formatlar
    // T�pk� �rnekteki 0.83 gibi.
    printf("Hesaplanan Sharpe Orani: %.2f\n", sharpe_orani);

    // --- YORUMLAMA (BONUS) ---
    // Hocan�n verdi�i kriterlere g�re oran� yorumluyoruz.
    if (sharpe_orani >= 3) {
        printf("Degerlendirme: Mukemmel (3 ve uzeri)\n");
    } else if (sharpe_orani >= 2) {
        printf("Degerlendirme: Cok Iyi (2 - 2.99 arasi)\n");
    } else if (sharpe_orani >= 1) {
        printf("Degerlendirme: Iyi (1 - 1.99 arasi)\n");
    } else {
        printf("Degerlendirme: Yeterince iyi degil (1'in altinda)\n");
    }

    // main fonksiyonu ba�ar�l� bir �ekilde bitti�inde 0 d�nd�r�r.
    return 0;
}
