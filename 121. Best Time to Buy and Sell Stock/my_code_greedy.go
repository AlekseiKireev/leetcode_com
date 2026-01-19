func maxProfit(prices []int) (Ans int) {

	globalMinPrice := prices[0]

	for _, price := range prices {
		Ans = max(Ans, price-globalMinPrice)
		globalMinPrice = min(globalMinPrice, price)
	}

	return Ans
}
