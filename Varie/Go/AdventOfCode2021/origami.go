package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"time"
)

type coordinates struct {
	x string
	y string
}

func calcolaMaxs(lineslice []string, X, Y int) (int, int) {
	x, _ := strconv.Atoi(lineslice[0])
	y, _ := strconv.Atoi(lineslice[1])
	if x > X {
		X = x
	}
	if y > Y {
		Y = y
	}
	return X, Y
}

func foldX(mappa map[coordinates]bool, numFold, maxX int) map[coordinates]bool {
	var a int
	for key, _ := range mappa {
		chiave := key
		a, _ = strconv.Atoi(chiave.x)
		if a > numFold {
			delete(mappa, key)
			a = maxX - a
			chiave.x = strconv.Itoa(a)
			if _, exist := mappa[chiave]; !exist {
				mappa[chiave] = true
			}
		}
	}
	return mappa
}

func foldY(mappa map[coordinates]bool, numFold, maxY int) map[coordinates]bool {
	var a int
	for key, _ := range mappa {
		chiave := key
		a, _ = strconv.Atoi(chiave.y)
		if a > numFold {
			delete(mappa, key)
			a = maxY - a
			chiave.y = strconv.Itoa(a)
			if _, exist := mappa[chiave]; !exist {
				mappa[chiave] = true
			}
		}
	}
	return mappa
}

func printPaper(mappa map[coordinates]bool, maxX, maxY int) [][]string {
	var matrix [][] string
	for key, _ := range mappa {
		X, _ := strconv.Atoi(key.x)
		Y, _ := strconv.Atoi(key.y)
		matrix[X][Y] = "* "
	}
	return matrix
}

func main() {
	start := time.Now()

	var cartesianPoint coordinates
	var mappa = make(map[coordinates]bool)
	var sliceNumeri, sliceComandi []string
	var maxX, maxY int

	file, err := os.Open("input2.txt")
	if err != nil {
		fmt.Println(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	scanner.Split(bufio.ScanLines)

	for i := 0; scanner.Scan(); i++ {
		if scanner.Text() == "" {
			break
		}
		sliceNumeri = strings.Split(scanner.Text(), ",")
		maxX, maxY = calcolaMaxs(sliceNumeri, maxX, maxY)
		cartesianPoint.x = sliceNumeri[0]
		cartesianPoint.y = sliceNumeri[1]
		mappa[cartesianPoint] = true
	}
	for i := 0; scanner.Scan(); i++ {
		sliceComandi = strings.Split(scanner.Text(), "=")
		for i := 0; i < len(sliceComandi)-1; i++ {
			if sliceComandi[0] == "fold along x" {
				numFold, _ := strconv.Atoi(sliceComandi[1])
				mappa = foldX(mappa, numFold, maxX)
				maxX /= 2
			} else if sliceComandi[0] == "fold along y" {
				numFold, _ := strconv.Atoi(sliceComandi[1])
				mappa = foldY(mappa, numFold, maxY)
				maxY /= 2
			} else {
				fmt.Println("ATTENZIONE COMANDO SBAGLIATO!")
			}
		}
	}

	fmt.Println(printPaper(mappa, maxX+1, maxY+1))

	//fmt.Println(len(mappa))
	fmt.Printf("--- %s ---", time.Since(start))
}
