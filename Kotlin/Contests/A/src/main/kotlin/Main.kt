private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val q = readInt()
    for (i in 1..q) {
        var (a, b) = readInts()
        if (a < b) {
            a = b.also {b = a}
            //Swap(a, b)
        }
        println("1 ${b - 1} ${a - b + 1}")
    }
}