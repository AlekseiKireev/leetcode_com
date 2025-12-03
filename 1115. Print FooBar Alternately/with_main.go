package main

import (
	"fmt"
	"sync"
)

type FooBar struct {
	n   int
	foo chan struct{}
	bar chan struct{}
}

func NewFooBar(n int) *FooBar {
	return &FooBar{
		n:   n,
		foo: make(chan struct{}),
		bar: make(chan struct{}),
	}
}

func (fb *FooBar) Foo(printFoo func()) {
	for i := 0; i < fb.n; i++ {

		printFoo()
		fb.foo <- struct{}{}
		<-fb.bar
	}
}

func (fb *FooBar) Bar(printBar func()) {
	for i := 0; i < fb.n; i++ {
		<-fb.foo
		printBar()
		fb.bar <- struct{}{}

	}
}

func main() {
	fb := NewFooBar(5)

	var wg sync.WaitGroup
	wg.Add(2)

	// foo-поток
	go func() {
		defer wg.Done()
		fb.Foo(func() { fmt.Print("foo") })
	}()

	// bar-поток
	go func() {
		defer wg.Done()
		fb.Bar(func() { fmt.Print("bar") })
	}()

	wg.Wait()
	fmt.Println()
}
