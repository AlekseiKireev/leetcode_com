package main

import (
	"fmt"
	"sync"
)

type ZeroEvenOdd struct {
	n      int
	zeroCh chan struct{}
	oddCh  chan int
	evenCh chan int
}

func NewZeroEvenOdd(n int) *ZeroEvenOdd {
	return &ZeroEvenOdd{
		n:      n,
		zeroCh: make(chan struct{}),
		oddCh:  make(chan int),
		evenCh: make(chan int),
	}
}

// printZero outputs 0
func (z *ZeroEvenOdd) Zero(printZero func(int)) {
	for i := 1; i <= z.n; i++ {
		printZero(0)

		if i%2 == 1 {
			z.oddCh <- i
		} else {
			z.evenCh <- i
		}

		<-z.zeroCh
	}

	close(z.oddCh)
	close(z.evenCh)
}

func (z *ZeroEvenOdd) Even(printEven func(int)) {
	for x := range z.evenCh {
		printEven(x)
		z.zeroCh <- struct{}{}
	}
}

func (z *ZeroEvenOdd) Odd(printOdd func(int)) {
	for x := range z.oddCh {
		printOdd(x)
		z.zeroCh <- struct{}{}
	}
}

func main() {
	n := 10

	zeo := NewZeroEvenOdd(n)

	var wg sync.WaitGroup
	wg.Add(3)

	printNumber := func(x int) {
		fmt.Print(x)
	}

	go func() {
		defer wg.Done()
		zeo.Zero(printNumber)
	}()

	go func() {
		defer wg.Done()
		zeo.Even(printNumber)
	}()

	go func() {
		defer wg.Done()
		zeo.Odd(printNumber)
	}()

	wg.Wait()
	fmt.Println()
}
