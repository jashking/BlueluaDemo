local m = {}

local Super = Super
local print = print
local LoadClass = LoadClass
local LoadStruct = LoadStruct
local GetEnum = GetEnum
local CreateFunctionDelegate = CreateFunctionDelegate

function m:Construct()
    print('LuaTestCaseWidget Construct')
    Super.TextBlock_1:SetText('')
    Super.Button_0.OnClicked:Add(CreateFunctionDelegate(Super, self, self.OnButton0Clicked))
    Super.Button_1.OnClicked:Add(CreateFunctionDelegate(Super, self, self.OnButton1Clicked))
end

function m:Destruct()
    print('LuaTestCaseWidget Destruct')
end

local FunctionNoParam = Super.FunctionNoParam

local EmptyFunctionOneIntParam = Super.EmptyFunctionOneIntParam
local EmptyFunctionTwoIntParam = Super.EmptyFunctionTwoIntParam
local EmptyFunctionThreeIntParam = Super.EmptyFunctionThreeIntParam
local EmptyFunctionFourIntParam = Super.EmptyFunctionFourIntParam
local EmptyFunctionFiveIntParam = Super.EmptyFunctionFiveIntParam

local EmptyFunctionOneStringParam = Super.EmptyFunctionOneStringParam
local EmptyFunctionTwoStringParam = Super.EmptyFunctionTwoStringParam
local EmptyFunctionThreeStringParam = Super.EmptyFunctionTwoStringParam
local EmptyFunctionFourStringParam = Super.EmptyFunctionFourStringParam
local EmptyFunctionFiveStringParam = Super.EmptyFunctionFiveStringParam

local EmptyFunctionOneVectorParam = Super.EmptyFunctionOneVectorParam
local EmptyFunctionTwoVectorParam = Super.EmptyFunctionTwoVectorParam
local EmptyFunctionThreeVectorParam = Super.EmptyFunctionThreeVectorParam
local EmptyFunctionFourVectorParam = Super.EmptyFunctionFourVectorParam
local EmptyFunctionFiveVectorParam = Super.EmptyFunctionFiveVectorParam

local EmptyFunctionMixParam = Super.EmptyFunctionMixParam

function m:OnButton0Clicked()
    Super.TextBlock_1:SetText('')

---[[
    self:TestFunction('FunctionNoParam', function () FunctionNoParam(Super) end)
    self:TestFunction('EmptyFunctionOneIntParam', function () local r = EmptyFunctionOneIntParam(Super, 1) end)
    self:TestFunction('EmptyFunctionTwoIntParam', function () local r = EmptyFunctionTwoIntParam(Super, 1, 2) end)
    self:TestFunction('EmptyFunctionThreeIntParam', function () local r = EmptyFunctionThreeIntParam(Super, 1, 2, 3) end)
    self:TestFunction('EmptyFunctionFourIntParam', function () local r = EmptyFunctionFourIntParam(Super, 1, 2, 3, 4) end)
    self:TestFunction('EmptyFunctionFiveIntParam', function () local r = EmptyFunctionFiveIntParam(Super, 1, 2, 3, 4, 5) end)

    self:TestFunction('EmptyFunctionOneStringParam', function () local r = EmptyFunctionOneStringParam(Super, '1') end)
    self:TestFunction('EmptyFunctionTwoStringParam', function () local r = EmptyFunctionTwoStringParam(Super, '1', '2') end)
    self:TestFunction('EmptyFunctionThreeStringParam', function () local r = EmptyFunctionThreeStringParam(Super, '1', '2', '3') end)
    self:TestFunction('EmptyFunctionFourStringParam', function () local r = EmptyFunctionFourStringParam(Super, '1', '2', '3', '4') end)
    self:TestFunction('EmptyFunctionFiveStringParam', function () local r = EmptyFunctionFiveStringParam(Super, '1', '2', '3', '4', '5') end)

    local KismetMathLibrary = LoadClass('KismetMathLibrary')
    local v = KismetMathLibrary:MakeVector(1, 2, 3)

    self:TestFunction('EmptyFunctionOneVectorParam', function () local r = EmptyFunctionOneVectorParam(Super, v) end)
    self:TestFunction('EmptyFunctionTwoVectorParam', function () local r = EmptyFunctionTwoVectorParam(Super, v, v) end)
    self:TestFunction('EmptyFunctionThreeVectorParam', function () local r = EmptyFunctionThreeVectorParam(Super, v, v, v) end)
    self:TestFunction('EmptyFunctionFourVectorParam', function () local r = EmptyFunctionFourVectorParam(Super, v, v, v, v) end)
    self:TestFunction('EmptyFunctionFiveVectorParam', function () local r = EmptyFunctionFiveVectorParam(Super, v, v, v, v, v) end)

    local r = KismetMathLibrary:MakeRotator(1, 2, 3)
    local t = KismetMathLibrary:MakeTransform(v, r, v)
    self:TestFunction('EmptyFunctionMixParam', function () EmptyFunctionMixParam(Super, 1, 1, '1', v, r, t, Super) end)
--]]
end

function m:OnButton1Clicked()
    Super.TextBlock_1:SetText('')

    Super.CPPCallScriptCount = 1000000

    local CostStr = Super:TestNativeCallScript()
    print(CostStr)

    Super.TextBlock_1:SetText(CostStr)
end

function m:TestFunction(name, func)
    local MaxLoopCount = 1000000

    local StartTime = Super:GetCycles()
    local LoopCount = 0

    while LoopCount < MaxLoopCount do
        func()
        LoopCount = LoopCount + 1
    end

    local EndTime = Super:GetCycles()
    local TimeCost = Super:GetSeconds(EndTime - StartTime)

    local CostStr = string.format('%s %0.5fs %d', name, TimeCost, MaxLoopCount)
    print(CostStr)

    Super.TextBlock_1:SetText(Super.TextBlock_1.Text .. '\n' .. CostStr)
end

function m:BP_FunctionNoParam()
end

function m:BP_EmptyFunctionOneIntParam(p1)
    return p1
end

function m:BP_EmptyFunctionTwoIntParam(p1, p2)
    return p1
end

function m:BP_EmptyFunctionThreeIntParam(p1, p2, p3)
    return p1
end

function m:BP_EmptyFunctionFourIntParam(p1, p2, p3, p4)
    return p1
end

function m:BP_EmptyFunctionFiveIntParam(p1, p2, p3, p4, p5)
    return p1
end

function m:BP_EmptyFunctionOneStringParam(p1)
    return p1
end

function m:BP_EmptyFunctionTwoStringParam(p1, p2)
    return p1
end

function m:BP_EmptyFunctionThreeStringParam(p1, p2, p3)
    return p1
end

function m:BP_EmptyFunctionFourStringParam(p1, p2, p3, p4)
    return p1
end

function m:BP_EmptyFunctionFiveStringParam(p1, p2, p3, p4, p5)
    return p1
end

function m:BP_EmptyFunctionOneVectorParam(p1)
    return p1
end

function m:BP_EmptyFunctionTwoVectorParam(p1, p2)
    return p1
end

function m:BP_EmptyFunctionThreeVectorParam(p1, p2, p3)
    return p1
end

function m:BP_EmptyFunctionFourVectorParam(p1, p2, p3, p4)
    return p1
end

function m:BP_EmptyFunctionFiveVectorParam(p1, p2, p3, p4, p5)
    return p1
end

function m:BP_EmptyFunctionMixParam(p1, p2, p3, p4, p5, p6, p7)
end

return m