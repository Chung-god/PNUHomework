package com.company.randomdice

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.ArrayAdapter
import android.widget.ListView
import kotlinx.android.synthetic.main.activity_main2.*
import kotlin.collections.List

class Main2Activity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main2)
        var scoreboard = ArrayList<Int>()
        scoreboard = intent.getIntegerArrayListExtra("ArrayList")
        ListView.adapter = ArrayAdapter(this, android.R.layout.simple_list_item_1, scoreboard)
    }
}