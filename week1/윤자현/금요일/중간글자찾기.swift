extension StringProtocol {
    subscript(offset: Int) -> Character {
        self[index(startIndex, offsetBy: offset)]
    }
}

func solution(_ s:String) -> String {
    
    let idx: Int = s.count / 2


    if s.count % 2 == 0 {
        return String(s[idx - 1]) + String(s[idx])
    } else {
        return String(s[idx])
    }
    return ""
    
}
