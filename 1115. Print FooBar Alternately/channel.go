type FooBar struct {
	n int
	foo chan struct{}
	bar  chan struct{}    
}

func NewFooBar(n int) *FooBar {
	return &FooBar{
        n: n,
        foo : make(chan struct{}),
        bar : make(chan struct{}),
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
