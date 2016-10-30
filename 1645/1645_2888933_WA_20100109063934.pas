var a:array[1..2000] of integer;
i,j,n,max,min:integer;
begin
readln(n);
for i:=1 to n do read(a[i]);
for i:=1 to n do begin
min:=1; 
max:=n;
for j:=1 to n do 
begin
if (j>i) and (a[j]<a[i]) then inc(min);
if (j<i) and (a[j]>a[i]) then dec(max);
end;
writeln(min,' ',max);
end;
end.