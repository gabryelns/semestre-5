program converteTemp(input, output);

var
    ch1: Char;
    ch2: Char;
    temp: Double;
    result: Double;

begin
    readln(ch1);
    readln(ch2);
    readln(temp);

    result := 0;

    if (ch1 = 'C') and (ch2 = 'K') then
        result := temp + 273.15
    else if (ch1 = 'C') and (ch2 = 'F') then
        result := (temp * (9/5)) + 32

    else if (ch1 = 'F') and (ch2 = 'K') then
        result := (temp-32) * 5/9 + 273.15
    else if (ch1 = 'F') and (ch2 = 'C') then
        result := (temp-32) * 5/9

    else if (ch1 = 'K') and (ch2 = 'C') then
        result := temp - 273.15
    else if (ch1 = 'K') and (ch2 = 'F') then
        result := (temp-273.15) * 9/5 + 32;

    writeln(result:0:2);
end.