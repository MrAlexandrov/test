private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val n = readLn().toInt()
    val a = readStrings().map { it.toInt() }
    val k = a.count({it == -1})
    var kk = k
    var ans = MutableList<MutableList<Int>>(k, {mutableListOf()})
    var ok = MutableList<Boolean>(k, {true})
    var ind = 0
    while (kk > 0) {
        var add = 0
        for (i in 0 until kk) {
            val j = ind + i
            if (a[j] == -1) {
                ok[i + add] = false
            } else {
                ans[i + add].add(a[j])
            }
        }
        ind += kk
        kk -= add
    }
    println(k)
    for (i in 0 until k) {
        print("${ans[i].size} ")
        for (j in ans[i]) {
            print("${j} ")
        }
        println()
    }
}