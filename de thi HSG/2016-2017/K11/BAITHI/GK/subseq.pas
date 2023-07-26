const MaxN = 10000;

var
    a: array[1..MaxN+1] of longint;
    n,k, dem_max: longint;


procedure nhap;
var i: longint;
begin
   readln(n,k);
   for i:=1 to n do read(a[i]);
   a[N+1] := k+1; // hang rao
end;
//-----------------------------------
procedure xuli;
var i,dem: longint;
begin
  dem_max := 0; dem := 0;
  for i:=1 to n+1 do
      if (a[i] mod k = 0) then inc(dem)
      else
          if dem > dem_max then begin dem_max := dem; dem := 0 end;

  write(dem_max);
end;
//-----------------------------------

begin
  assign(input,'subseq.inp'); reset(input);
  assign(output,'subseq.out'); rewrite(output);
  nhap;
  xuli;
  close(input); close(output);
end.
