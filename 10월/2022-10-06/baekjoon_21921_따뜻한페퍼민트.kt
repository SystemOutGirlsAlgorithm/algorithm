fun main() {
    val (N, X) = readln().trim().split(' ').map{it.toInt()}
    readln().trim().split(' ').map{it.toInt()}
        .let{ arrayList ->
            arrayList.runningReduceIndexed { index, acc, i ->
            acc + i - arrayList.getOrElse(index-X){0}
        }.let { result ->
                result.maxOrNull()?.takeIf { it > 0 }?.let { answer ->
                    println(answer)
                    println(result.count { it == answer })
                } ?: println("SAD")
            }
        }

}