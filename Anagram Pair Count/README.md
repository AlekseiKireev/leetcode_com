https://t.me/algoses_chat/41

    Задача с собеседования в Яндекс
    Даются n строк. Гарантируется, что строки состоят из латинских букв в нижнем регистре. 
    Две строки равны между собой, если можно так переставить буквы в них, чтобы они стали равны. 
    Ваша задача найти количество пар (i, j), что строки s[i] и s[j] равны. 
    
    Решение:
    Очевидно, две строки s и t раны, тогда и только тогда, когда sort(s) = sort(t), 
    но если будем сортировать все слова и дальше записывать в словарь количество вхождений это займет больше чем линейное время, засчет сортировки строк. 
    
    Давайте для каждой строки s[i] мы заведем вектор vec[i] = [] который будет хранить 26 чисел, где vec[i][j] = количеству вхождений в строке i буквы j. 
    Тогда очевидно строки s[i] = s[j] если vec[i] = vec[j]. 
    Каждый такой вектор мы запишем в словарь и зная количество вхождений определенного вектора мы сможем узнавать количество пар. 
