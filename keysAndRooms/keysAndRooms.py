from typing import List
from queue import Queue

class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = set()
        toVisit = Queue()
        toVisit.put(0)
        while not toVisit.empty():
            room = toVisit.get()
            visited.add(room)
            for key in rooms[room]:
                if key not in visited:
                    toVisit.put(key)
        return (len(visited) == len(rooms))