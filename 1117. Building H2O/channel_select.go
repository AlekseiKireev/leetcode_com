type H2O struct {
	h1ch chan struct{} // первый H
	h2ch chan struct{} // второй H
	och  chan struct{} // O
}

func NewH2O() *H2O {
	h := &H2O{
		h1ch: make(chan struct{}, 1),
		h2ch: make(chan struct{}, 1),
		och:  make(chan struct{}, 1),
	}

	// запускаем цикл с ожидания первого H
	h.h1ch <- struct{}{}

	return h
}

func (h2o *H2O) Hydrogen(releaseHydrogen func()) {
	select {
	case <-h2o.h1ch:
		// после первого H разрешаем второй H
		h2o.h2ch <- struct{}{}
	case <-h2o.h2ch:
		// после второго H разрешаем кислород
		h2o.och <- struct{}{}
	}

	releaseHydrogen()
}

func (h2o *H2O) Oxygen(releaseOxygen func()) {
	// O можно выпустить только после двух H
	<-h2o.och

	// запускаем всё по кругу — снова ждём первый H
	h2o.h1ch <- struct{}{}

	releaseOxygen()
}

// error
/*
package main

import (
	"fmt"
	"sync"
)

type H2O struct {
	h1ch chan struct{} // первый H
	h2ch chan struct{} // второй H
	och  chan struct{} // O
}

func NewH2O() *H2O {
	h := &H2O{
		h1ch: make(chan struct{}, 1),
		h2ch: make(chan struct{}, 1),
		och:  make(chan struct{}, 1),
	}

	// запускаем цикл с ожидания первого H
	h.h1ch <- struct{}{}

	return h
}

func (h2o *H2O) Hydrogen(releaseHydrogen func()) {
	select {
	case <-h2o.h1ch:
		// после первого H разрешаем второй H
		h2o.h2ch <- struct{}{}
	case <-h2o.h2ch:
		// после второго H разрешаем кислород
		h2o.och <- struct{}{}
	}

	releaseHydrogen()
}

func (h2o *H2O) Oxygen(releaseOxygen func()) {
	// O можно выпустить только после двух H
	<-h2o.och

	// запускаем всё по кругу — снова ждём первый H
	h2o.h1ch <- struct{}{}

	releaseOxygen()
}

func main() {
	h2o := NewH2O()

	var wg sync.WaitGroup

	// входные данные как на LeetCode — например HHOOHHOO
	input := "HHOOHHOO"

	for _, c := range input {
		wg.Add(1)
		if c == 'H' {
			go func() {
				defer wg.Done()
				h2o.Hydrogen(func() { fmt.Print("H") })
			}()
		} else {
			go func() {
				defer wg.Done()
				h2o.Oxygen(func() { fmt.Print("O") })
			}()
		}
	}

	wg.Wait()
	fmt.Println()
}

*/
