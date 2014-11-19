package com.longtech.games;

import java.util.Random;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TableRow;
import android.widget.Toast;

public class DroidLightsOutActivity extends Activity implements OnClickListener {
	static final int ROWS = 5, COLS = 5;
	static final int row[] = { R.id.tableRow0, R.id.tableRow1, R.id.tableRow2,
			R.id.tableRow3, R.id.tableRow4 };

	static final int col[] = { R.id.button0, R.id.button1, R.id.button2,
			R.id.button3, R.id.button4 };
	boolean cellState[][] = new boolean[ROWS][COLS];

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		Button tmp;
		for (int r = 0; r < ROWS; r++) {
			for (int c = 0; c < COLS; c++) {
				tmp = getCell(r, c);
				if (tmp != null) {
					tmp.setOnClickListener(this);
					tmp.setTag(r + "_" + c);
					cellState[r][c] = new Random().nextBoolean();
					tmp.setSelected(cellState[r][c]);
					tmp.setText(cellState[r][c] ? "On" : "Off");
				}
			}
		}
	}

	public void onClick(View v) {
		String tag = (String) v.getTag();
		if (tag.contains("_")) {
			int r = -1, c = -1, idx = tag.indexOf("_");
			r = Integer.parseInt(tag.substring(0, idx));
			c = Integer.parseInt(tag.substring(idx + 1, tag.length()));
			cellState[r][c] = !cellState[r][c];

			if (hasWon()) {
				Toast.makeText(this, "You Win!", Toast.LENGTH_LONG);
			}
		}
	}

	private boolean hasWon() {
		for (int r = 0; r < ROWS; r++) {
			for (int c = 0; c < COLS; c++) {
				if (!cellState[r][c]) {
					return false;
				}
			}
		}
		return true;
	}

	private Button getCell(int r, int c) {
		TableRow tr = (TableRow) this.findViewById(row[r]);
		return (Button) tr.findViewById(col[c]);
	}
}
