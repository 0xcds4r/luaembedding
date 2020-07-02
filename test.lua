-- Test.lua

function blablafuncLua(a, b)
	print("called! blablafuncLua("..a..", "..b..") [LUA]")

	blablafuncCPP(487, 999); -- call registered function with our value
end