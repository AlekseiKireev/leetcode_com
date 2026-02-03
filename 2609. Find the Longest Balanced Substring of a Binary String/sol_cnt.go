func findTheLongestBalancedSubstring(s string) (maxi int) {
	
	for i := 0; i < len(s); { // указатель смещается в циклах ниже: 
							  // цикл по '1' после окончания указывает либо на '1', либо на конец строки
		zeros, ones := 0, 0

		for ;i < len(s) && s[i] == '0'; i++{
			zeros++			
		}
		for ;i < len(s) && s[i] == '1'; i++{
			ones++			
		}

		maxi = max(maxi, min(zeros, ones)) /*2*min необходим ввиду: ...00111...*/
	}
  
	return 2*maxi
}
