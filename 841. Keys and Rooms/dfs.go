func canVisitAllRooms(rooms [][]int) bool {
	used := make([]bool, len(rooms))
	cntUsedKey := 0
	dfs(0, rooms, used, &cntUsedKey)
	return cntUsedKey == len(rooms)
}

func dfs(roomKey int, rooms [][]int, used []bool, cntUsedKey *int) {
	// rooms = [[1],[2],[3],[0]]
	*cntUsedKey++
	used[roomKey] = true
	for _, key := range rooms[roomKey] {

		if used[key] == false {

			dfs(key, rooms, used, cntUsedKey)
		}

	}
}
