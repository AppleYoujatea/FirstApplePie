func solution(_ arr:[Int]) -> [Int] {
        var temp = arr
        var min = arr.max()!
        var index = 0
        for i in 0..<temp.count {
            if min >= arr[i]{
                min = arr[i]
                index = i
            }
        }
        
        temp.remove(at:index)
        
        if temp.count > 0 {
            return temp
        } else {
            temp = [-1]
            return temp
        }
}
