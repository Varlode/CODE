uses math;
var tn1, tn2: char;
    Tc, Tf, Tk: real;

procedure nhap;
begin
    read(tn1);
    if tn1 = 'C' then readln(Tc);
    if tn1 = 'F' then readln(Tf);
    if tn1 = 'K' then readln(Tk);
    readln(tn2);
end;

function doiCF(Tc:real):real;
begin
   doiCF := 1.8 * Tc + 32;
end;

function doiFK(Tf:real):real;
begin
   doiFK := (Tf + 459.67)/1.8;
end;

function doiFC(Tf:real):real;
begin
   doiFC := (Tf-32)/1.8;
end;

function doiKF(Tk:real):real;
begin
   doiKF := 1.8*Tk - 459.67;
end;


procedure xuli;
begin
   if (tn1 = 'C') then
     begin
       if (tn2 = 'F') then write(doiCF(Tc):0:2);
       if (tn2 = 'K') then write(doiFK(doiCF(Tc)):0:2);
     end;
   if (tn1 = 'F') then
     begin
       if (tn2 = 'C') then write(doiFC(Tf):0:2);
       if (tn2 = 'K') then write(doiFK(Tf):0:2);

     end;
   if (tn1 = 'K') then
     begin
       if (tn2 = 'C') then write(doiFC(doiKF(Tk)):0:2);
       if (tn2 = 'F') then write(doiKF(Tk):0:2);
     end;
end;


BEGIN
  assign(input,'thangnhiet.inp'); reset(input); assign(output,'thangnhiet.out'); rewrite(output);
  nhap;
  xuli;
  close(input); close(output);
END.
