package main

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
