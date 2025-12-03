package main

import (
	"fmt"
	"sync"
)

type Foo struct {
	second chan struct{}
	third  chan struct{}
}

func NewFoo() *Foo {
	return &Foo{
		second: make(chan struct{}),
		third:  make(chan struct{}),
	}
}

func (f *Foo) First(printFirst func()) {
	printFirst()
	f.second <- struct{}{}
}

func (f *Foo) Second(printSecond func()) {
	<-f.second
	printSecond()
	f.third <- struct{}{}
}

func (f *Foo) Third(printThird func()) {
	<-f.third
	printThird()
}

func main() {
	foo := NewFoo()
	var wg sync.WaitGroup

	// функции, которые ожидает LeetCode
	printFirst := func() { fmt.Print("first") }
	printSecond := func() { fmt.Print("second") }
	printThird := func() { fmt.Print("third") }

	// запуск трёх горутин в произвольном порядке
	wg.Add(3)

	go func() {
		defer wg.Done()
		foo.Third(printThird)
	}()
	go func() {
		defer wg.Done()
		foo.First(printFirst)
	}()

	go func() {
		defer wg.Done()
		foo.Second(printSecond)
	}()

	wg.Wait()
	fmt.Println()
}
