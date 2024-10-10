package com.example.numconverter;

import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private EditText inputNumber;
    private Spinner inputType, outputType;
    private TextView outputResult;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        inputNumber = findViewById(R.id.inputNumber);
        inputType = findViewById(R.id.inputType);
        outputType = findViewById(R.id.outputType);
        Button convertButton = findViewById(R.id.convertButton);
        outputResult = findViewById(R.id.outputResult);

        // Populate input type Spinner
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this,
                R.array.number_types, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        inputType.setAdapter(adapter);
        outputType.setAdapter(adapter); // Assuming both spinners use the same types


        convertButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                convertNumber();
            }
        });
    }

    private void convertNumber() {
        String number = inputNumber.getText().toString();
        String inputTypeStr = inputType.getSelectedItem().toString();
        String outputTypeStr = outputType.getSelectedItem().toString();

        String result = "";

        if (inputTypeStr.equals("Decimal")) {
            int decimalValue = Integer.parseInt(number);
            result = convertDecimalToOther(decimalValue, outputTypeStr);
        } else if (inputTypeStr.equals("Binary")) {
            int decimalValue = Integer.parseInt(number, 2);
            result = convertDecimalToOther(decimalValue, outputTypeStr);
        } else if (inputTypeStr.equals("Octal")) {
            int decimalValue = Integer.parseInt(number, 8);
            result = convertDecimalToOther(decimalValue, outputTypeStr);
        } else if (inputTypeStr.equals("Hexadecimal")) {
            int decimalValue = Integer.parseInt(number, 16);
            result = convertDecimalToOther(decimalValue, outputTypeStr);
        }

        outputResult.setText(result);
    }

    private String convertDecimalToOther(int decimalValue, String outputType) {
        switch (outputType) {
            case "Decimal":
                return String.valueOf(decimalValue);
            case "Binary":
                return Integer.toBinaryString(decimalValue);
            case "Octal":
                return Integer.toOctalString(decimalValue);
            case "Hexadecimal":
                return Integer.toHexString(decimalValue).toUpperCase();
            default:
                return "";
        }
    }
}
