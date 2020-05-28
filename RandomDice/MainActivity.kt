package com.company.randomdice

import java.util.Random
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_main.*
import android.widget.Toast

class Main1Activity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        var pointList = ArrayList<Int>()
        var i = 0;
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main2)
        fun dice(arr: ArrayList<Int>, num: Int): ArrayList<Int> {
            //10 까지 랜덤 수 출력
            var random = Random()
            var input: Int = random.nextInt(11)
            var x = num;
            var n = 15
            println(input)
            if (x != 0 && arr[x - 1] == input) {
                input += 10
                if (input >= 15) {
                    arr.add(n)
                    return arr
                }
            }
            arr.add(input)
            return arr
        }

        Button.setOnClickListener {
            if (i != 20) {
                pointList = dice(pointList, i++)
            } else {
                var nextIntent = Intent(this, Main2Activity::class.java)
                nextIntent.putExtra("ArrayList", pointList)
                startActivity(nextIntent)
            }

            Toast.makeText(this, "${pointList.get(i - 1)}", Toast.LENGTH_SHORT).show()
        }
    }
}