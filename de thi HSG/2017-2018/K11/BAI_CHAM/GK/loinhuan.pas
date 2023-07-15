uses math;
const
      maxN = 100000;
      fi = 'loinhuan.inp';
      fo = 'loinhuan.out';

var
      n,luuj : longint;
      a,vt: array[1..maxN] of longint;
      Sum,Sum1: array[0..maxN] of longint;

procedure Enter;
var i: longint;
begin
   readln(n);
   for i:=1 to n do read(a[i]);
end;
//--------------------------------------
procedure DoiCho(var a,b:longint);
var tam: longint;
begin
  tam := a; a := b;  b := tam;
end;
//---
Procedure QuickSort(L,H:longint);
Var i,j, Chot: longint;
Begin
  If L>=H then Exit;
  Chot := Sum1[(L+H) div 2];
  i := L;
  j := H;
  Repeat
    While Sum1[i] < Chot do inc(i);
    While Sum1[j] > Chot do dec(j);
    If i<=j then
      Begin
        If i<j then begin DoiCho(Sum1[i],Sum1[j]);  Doicho(vt[i],vt[j]) end;
        Inc(i); Dec(j);
      End;
  Until i>j;
  QuickSort(L,j);
  QuickSort(i,H);
End;

//--------------------------------------
procedure tim(x,a,b:longint);
var L,H,Mid: longint;
begin
  if a>b then exit;
  L := a; H := b;
  Mid := (L+H) div 2;
  if Sum1[Mid] = x then
     begin
          if vt[Mid]>luuj then luuj := vt[Mid];
          tim(x,Mid+1,H);
          tim(x,L,Mid-1);
     end
  else
        begin
           if x < Sum1[Mid] then tim(x,L,Mid - 1)
           else tim(x,Mid + 1,H);
        end;
end;
//--------------------------------------
procedure Process;
var i,j,Lmax: longint;
begin
   Fillchar(Sum,SizeOf(Sum),0);
   For i:=1 to n do
     Begin
       Sum[i] := Sum[i-1] + a[i];
       vt[i] := i;
     End;
   Sum1 := Sum;
   QuickSort(1,n);

   Lmax := 0;
   for i:=1 to n do
     begin
       luuj := 0;
       tim(Sum[i-1],1,n);
       if luuj>0 then
         Begin
           if (luuj-i+1) > Lmax then Lmax := (luuj-i+1);
         end;
     end;
  if Lmax <= 0 then write(-1)
  else write(Lmax);
end;
//--------------------------------------
BEGIN
  assign(input,fi); reset(input);
  assign(output,fo); rewrite(output);

    Enter;
    Process;

  close(input); close(output);
END.
