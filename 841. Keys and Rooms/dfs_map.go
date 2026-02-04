func canVisitAllRooms(rooms [][]int) bool {

    used := make(map[int]bool, len(rooms))
	dfs(0, rooms, used)
	return len(used) == len(rooms)
}

func dfs(roomKey int, rooms [][]int, used map[int]bool) {
	used[roomKey] = true
	for _, key := range rooms[roomKey] {
		
		if used[key] == false {
			dfs(key, rooms, used)
		}

	}
}
