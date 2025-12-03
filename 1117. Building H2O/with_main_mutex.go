package main

import (
	"fmt"
	"sync"
)

// H2O: правильная реализация с семафорами
type H2O struct {
	hSem  chan struct{} // разрешения для H (max 2)
	oSem  chan struct{} // разрешение для O (1 когда есть 2 H)
	mutex sync.Mutex
	count int // сколько H пришло для текущей молекулы (0..1)
}

func NewH2O() *H2O {
	h := &H2O{
		hSem: make(chan struct{}, 2),
		oSem: make(chan struct{}, 1),
	}
	// сразу даём два разрешения для H (первым двум H можно идти)
	h.hSem <- struct{}{}
	h.hSem <- struct{}{}
	return h
}

func (h2o *H2O) Hydrogen(releaseHydrogen func()) {
	<-h2o.hSem               // ждём разрешения для H
	releaseHydrogen()        // печатаем H

	h2o.mutex.Lock()
	h2o.count++
	if h2o.count == 2 {
		// набралось 2 H -> разблокируем Oxygen
		h2o.count = 0
		h2o.oSem <- struct{}{}
	}
	h2o.mutex.Unlock()
}

func (h2o *H2O) Oxygen(releaseOxygen func()) {
	<-h2o.oSem            // ждём пока будет 2 H
	releaseOxygen()       // печатаем O

	// после O возвращаем два разрешения для H (новая молекула)
	h2o.hSem <- struct{}{}
	h2o.hSem <- struct{}{}
}
