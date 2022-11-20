package main

import (
  "bufio"
  "fmt"
  "os"
  "strings"
  "time"
  "strconv"
)

func main() {

  var inputSlice []string
  var days, contatore int
  var sumFishes, numOfFishes int 
  var fishAges []int


  file, err := os.Open("C:\\Users\\eliac\\Desktop\\Go\\Advent of code\\prova.txt")
  if err != nil {
    fmt.Println(err)
  }
  defer file.Close()


  scanner := bufio.NewScanner(file)
  for scanner.Scan() {
    inputSlice = strings.Split(scanner.Text(), ",")
  }

  
  fmt.Print("Quanti giorni vuoi calcolare? ")
  fmt.Scan(&days)

  
  start := time.Now()

  
  for i := 0; i < 8; i++ {
    for _, value := range inputSlice {
      v, _ := strconv.Atoi(value)
      if v == i {
        contatore++
      }
    }

    fishAges[i] = contatore
    contatore = 0
  }

  fmt.Println(fishAges)

  for i := 0; i < days; i++ {
    calculateFishes(fishAges)
    sumFishes += numOfFishes
  }

  fmt.Println(sumFishes)

  fmt.Println(time.Since(start))
}

func calculateFishes(numFishes []int) int {
  var numOfFishes int
  for i := 0; i < 8; i++ {
    if i-1 < 0 {
      numFishes[i] = numFishes[0]
    } else {
      numFishes[i] = numFishes[i-1]
    }
    numFishes[8] += numFishes[0]
    numFishes[6] += numFishes[0]
    for _, value := range numFishes {
      numOfFishes += value
    }
  }
  return numOfFishes
}