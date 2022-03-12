# ATP-Cup
Creating automated results at a tennis tournament

Pentru a putea rezolva problema propusa, am creat mai multe fisiere .c si .h
Fisierele list stack si bst contin functiile si structurile necesare pentru lucrul cu:
1. o lista dublu inlantuita circulara cu santinela ce contine ca valori structuri de tip tara din campionat
2. o stiva care va contine lista tarilor 
3. o stiva pentru castigatorii meciurilor
4. o stiva auxialara pentru aputea retine ultime 4 tari din capionat necesare pentru a patra cerinta
5. un BST in care sa se introduca jucatorii acelor 4 tari


Fiserele structures.h si utils.h desemneaza structurile Country si Player, respectiv bibliotecile standard de care este nevoie in majoritatea celorlalte functiilor.
- Functia readQuery realizeaza citirea fisierului cerinte.in si apeleaza functiile "mari" ce rezolva cerintele. Am parcurs rand pe rand fiecare valoare de 1 din acest fisier pentru a asigura o particularizare a fiecarei cerinte si pentru a aloca corespunzator variabilele necesare. Daca cerinta 2 si 4 se legau de cerinta 1 si 3, le-am tratat in legatura una cu alta. De aceea nu exista si o functie task4. I
- Functia removeMin ajuta la eliminarea tarilor care corespund cerintei 2.
- Pentru task3 si task5 am avut nevoie si de alte functii pentru a afla scorul maxim dintre doua tari sau scorul maxim al jucatorilor din doua echipe. 
- Initial introduc in coada doar primul jucator din prima echipa si apoi ii includpe rand pe toti jucatorii din cealalta echipa, realizand meciurile. Urmatorul pas este sa scot din coada primul jucator din echipa 1, sa adaug la final al doilea jucator si sa realizez meciul cu primul jucator din a doua echipa ce se afla acum in varful cozii. Scot si acest jucator din echipa 2 si il audaug la finalul cozii, insa retin inainte valoarea jucatorului din echipa 1 si o adaug iar in coada. Se repeta pana cand am terminat de jucat toate meciurile ce il includ pe al doilea jucator. Pentru restul jucatorilor din prima echipa, voi scoate in primul rand varful din coada pentru ca acesta contine un coechipier.Acum un jucator din a doua echipa cu care pot avea un meci. Se continua procedeul, retinand si readaugand acel jucator din prima echipa. 

