local m = {}

local Super = Super
local print = print
local LoadClass = LoadClass
local LoadStruct = LoadStruct
local GetEnum = GetEnum

function m:ReceiveBeginPlay()
    print('LuaTestCaseActor begin play in lua' .. Super.LuaFilePath)
end

function m:TestBPEmptyFunction()
    print('TestBPEmptyFunction in lua')
end

function m:TestBPFunction1(Param1, Param2, Param3)
    local KismetMathLibrary = LoadClass('KismetMathLibrary')

    local scale = KismetMathLibrary:MakeVector(3, 2, 1)
    local out_v = KismetMathLibrary:MakeVector(Param1.X * 2, Param1.Y * 2, Param1.Z * 2)
    local out_r = KismetMathLibrary:MakeRotator(Param3.Roll * 2, Param3.Pitch * 2, Param3.Yaw * 2)
    local out_t = KismetMathLibrary:MakeTransform(out_v, out_r, scale)

    return out_t, out_v, out_r
end

return m