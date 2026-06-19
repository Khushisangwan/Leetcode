func largestAltitude(gain []int) int {
    var sum, maxsum int
	for _, g := range gain {
		sum += g
		maxsum = max(maxsum, sum)
	}
	return maxsum
}