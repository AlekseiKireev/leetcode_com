func findTheLongestBalancedSubstring(s string) (maxi int) {
	
	for i := 0; i < len(s); {
		zeros, ones := 0, 0

		for ;i < len(s) && s[i] == '0'; i++{
			zeros++			
		}
		for ;i < len(s) && s[i] == '1'; i++{
			ones++			
		}

		maxi = max(maxi, 2*min(zeros, ones))
	}
  
	return maxi
}
