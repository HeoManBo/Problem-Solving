import java.util.*



fun main(){
    val pq : PriorityQueue<Int> = PriorityQueue()
    val N  = readLine()!!.toInt()
    for(i in 0 until N){
        val num = readLine()!!.toInt()
        pq.add(num)
    }
    var sum : Long = 0
    while(pq.isNotEmpty()){
        if(pq.size == 1){
            break;
        }
        val num1 = pq.peek()
        pq.poll()
        val num2 = pq.peek()
        pq.poll()
        sum += num1 + num2
        pq.add(num1+num2)
    }
    println(sum)
}