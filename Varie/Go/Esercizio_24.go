/*Dato n stampa i primi n primi*/
package main

import (
	"fmt"
	"math"
)

func isPrime(x int) bool {
	var d int
	for d = 2; d < x; d++ {
		if x%d == 0 {
			return false
		}
	}
	return true
}
func main() {
	var n int
	np := 2
	fmt.Print("numero: ")
	fmt.Scan(&n)
	for i := 2; i < (n + 2); i++ {
		if isPrime(i) {
			np++
			fmt.Println(i, "\t", "PIGRECO", float64(np), "---------", (float64(i) / math.Log(float64(i))), "-----------", int(float64(np)/(float64(i)/math.Log(float64(i)))))
		} else {
			n++
		}
	}
	fmt.Println(np-2, "NP")
}
