private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun solve() : Boolean {
    val s = readLine()!!
    val t = readLine()!!
    var i = 0
    var j = 0
    while (i < s.length && j < t.length) {
        if (s[i] == t[j]) {
            i++
            j++
        } else {
            if (s[i] == '+' && t[j] == '-') {
                return false
            } else {
                if (i == s.length - 1 || s[i + 1] == '+') {
                    return false
                } else {
                    i += 2
                    j++
                }
            }
        }
    }
    return (i == s.length && j == t.length)
}

fun main(args: Array<String>) {
    val t = readInt()
    for (i in 0 until t) {
        println(if (solve()) "YES" else "NO")
    }
}