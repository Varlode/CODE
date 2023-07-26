uses math;
const
      MaxN = 100000;
      fi = 'daydan.inp';
      fo = 'daydan.out';
var  L: array[1..MaxN] of longint;
     k,N: longint;
     Max: longint;
function Kiemtra(x:int64): boolean;
var i,dem: longint;
begin
   dem := 0;
   for i:=1 to n do
     begin
      dem := dem + (L[i] div x);
      if dem >= k then exit(true);
     end;
  exit(false);
end;
//----------------------------------
procedure xuli;
var i,j: longint; sum: int64; Lmax,Lmin,median,Dmax: int64;
begin
  Sum := 0; Max := 0; Dmax := 0;
  for i:=1 to n do // tim tong chieu dai cac doan day va tim doan dai nhat
   begin
    sum := sum + L[i];
    if Dmax < L[i] then Dmax := L[i];
   end;
   Lmax := min(Dmax,sum div k);  // chieu dai doan cat lon nhat co the
   Lmin := 1;
  while Lmax>=Lmin do  // tim Max bang cach chia nhi phan
    begin
      median := (Lmax + Lmin) div 2;  // lay chieu dai doan cat trung binh
      if kiemtra(median) then
        begin
          Max := median;
          Lmin := median +1;
        end
      else Lmax := median -1;
    end;
  write(Max);
end;
//---------------------------------------
procedure nhap;
 var i: longint;
 begin
    readln(n,k);
    for i:= 1 to n do readln(L[i]);
 end;
//--------------------------------
BEGIN
assign(input,fi); reset(input);
assign(output,fo); rewrite(output);
  nhap;
  xuli;
close(input); close(output);
END.
