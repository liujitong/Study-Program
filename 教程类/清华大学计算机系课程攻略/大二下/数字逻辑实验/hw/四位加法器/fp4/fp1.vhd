library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity fp1 is
	port(
		a,b,cin:in std_logic;
		s,cout:out std_logic;
		p,g:buffer std_logic
	);
end fp1;

architecture plus of fp1 is
begin
	process(a,b)
	begin
		p<=a xor b;
		g<=a and b;
	end process;
	process(cin,p,g)
	begin
		s<=p xor cin;
		cout<=g or (cin and p);
	end process;
end plus;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity fp4 is
	port(
		a,b:in std_logic_vector(3 downto 0);
		cin:in std_logic;
		s:out std_logic_vector(3 downto 0);
		cout:out std_logic
	);
end fp4;
