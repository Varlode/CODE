const
      fi = 'Dathuc.inp';
      fo = 'Dathuc.out';
      MaxN = 50000;

var
     Heso: array[0..MaxN] of longint;
     Horner: array[0..MaxN] of int64;
     N,x: Longint;

procedure nhap;
var i: Longint;
begin
  Readln(x,N);
  For i:=N downto 0 do Read(Heso[i]);
end;
//-------------------------------------
procedure xuli;
var i: longint;
begin
  for i:=N downto 0 do
    if i=N then Horner[i] := Heso[i]
    else Horner[i] := x*Horner[i+1]+Heso[i];
  Write(Horner[0]);
end;
//--------------------------------------
{function luythua(x,k:longint): int64;
var i: longint; LT: int64;
begin
  if k=0 then exit(1);
  if k=1 then exit(x);
  LT := x;
  for i:=2 to k do LT := LT*x;
  exit(LT);
end;


procedure xuli;
var i: longint; P: int64;
begin
  P:=0;
  for i:=0 to N do P := P + Heso[i]*luythua(x,i);
  write(P);
end;}
//--------------------------------------
BEGIN

    assign(Input,fi); reset(Input);
    assign(Output,fo); rewrite(Output);

       Nhap;
       xuli;

    Close(Input);
    Close(Output);
END.
