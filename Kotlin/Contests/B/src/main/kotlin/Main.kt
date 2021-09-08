private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val n = readInt()
    val a = readInts()
    var ans = 0
    var mx1 = 0
    var mx2 = 0
    for (x in a) {
        if (mx2 > x) {
            ans++
        } else {
            if (x > mx1) {
                mx2 = mx1
                mx1 = x
            } else {
                mx2 = x
            }
        }
    }
    print(ans)
}