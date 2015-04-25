# Plecaki

Kod zalicza testy na 100%


Wycieczka

Ania i Bartek wybierają się na długą wycieczkę. Potrzebują dużo energii, więc chcą zapakować do swoich plecaków jak najwięcej jak najbardziej wartościowej żywności. Nie mogą jednak się przeciążać – każde z nich ma limit wagi plecaka, którego nie może przekroczyć. Do dyspozycji mają określoną liczbę pojedynczych rzeczy do jedzenia (kanapki, batony itp.). Pomóż im przy pakowaniu.
Wejście

Dane zostaną wprowadzone w następującym formacie:
ua ub
n
w1 c1
w2 c2
...
wn cn
gdzie: ua to udźwig plecaka Ani, ub to udźwig plecaka Bartka, n to liczba rzeczy do jedzenia, wi to waga i-tej rzeczy zaś ci to jej wartość energetyczna (całości). Wszystkie wagi są podane w kilogramach z dokładnością do jednego miejsca po przecinku (np. 2 kilogramy będą wprowadzone w postaci 2.0).
Ograniczenia: 0.1 ≤ ua ≤ 200, 0.1 ≤ ub ≤ 200, 1 ≤ n ≤ 1000, 0.1 ≤ wi ≤ 200, 1 ≤ ci ≤ 1000000.
Uwaga: każdy z przedmiotów można tylko raz "wybrać" do rozwiązania, ale może pojawić się kilka przedmiotów o takiej samej wadze i wartości energetycznej.
Wyjście

Na wyjściu należy wypisać łączną wartość energetyczną wszystkich spakowanych przedmiotów.
Przykład

Wejście
0.7 0.8
8
0.1 50
0.3 300
0.3 300
0.3 300
0.3 300
0.4 350
0.4 350
0.4 350

Wyjście
1350
Objaśnienie przykładu:
Rozwiązanie to wkłada drugi i i piąty przedmiot to plecaka Ani (dając 650 kalorii przy wadze 0.7kg), do plecaka Bartka trafiają przedmioty szósty i siódmy (700 kalorii przy wadze 0.8kg).
