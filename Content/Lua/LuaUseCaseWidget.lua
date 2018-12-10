local m = {}

local Super = Super
local print = print
local LoadClass = LoadClass
local CreateDelegate = CreateDelegate
local DeleteDelegate = DeleteDelegate

-- Override UserWidget Construct Event
function m:Construct()
    print('LuaUseCaseWidget Construct')

    -- load UTestObject's class
    local TestObjectClass = LoadClass('TestObject')

    -- new a UTestObject instance
    local TestObjectInstance = TestObjectClass(Super)
    print('TestObjectInstance is', tostring(TestObjectInstance))

    -- write to parent's class member
    Super.StrValue = 'StrValue'

    -- binding delegate to parent widget's button
    Super.Button1.OnClicked:Add(function() print('Button1 OnClicked') end)

    local KismetSystemLibrary = LoadClass('KismetSystemLibrary')
    self.TimerDelegate = CreateDelegate(Super, self, self.DelegateCallback)
    KismetSystemLibrary:K2_SetTimerDelegate(self.TimerDelegate, 1, true)

    Super:TestFunction2(false, 200)
end

local count = 0
function m:DelegateCallback()
    count = count + 1
    print('DelegateCallback', tostring(self))
    if count > 10 and self.TimerDelegate then
        DeleteDelegate(self.TimerDelegate)
        self.TimerDelegate = nil
    end
end

-- Override UserWidget Destruct Event
function m:Destruct()
    print('LuaUseCaseWidget Destruct')
end

-- Override UseCaseWidget TestScriptFunction Event
function m:TestScriptFunction()
    print('Lua TestScriptFunction get called')

    -- call parent's TestFunction
    local v = Super:TestFunction()
    return v
end

-- Override UseCaseWidget TestScriptFunctionWithParam Event
function m:TestScriptFunctionWithParam(Param1, Param2)
    print('Lua TestScriptFunctionWithParam get called')
    print('Param1 is', Param1)
    print('Param2 is', Param2.X, Param2.Y, Param2.Z)

    -- call parent's TestFunctionWithParam
    local v = Super:TestFunctionWithParam(Param1, Param2)
    return v
end

function m:TestLuaOverrideBPFunction(Param1, Param2, Param3, Param4, Param5, Param6, Param7, Param8, Param9, Param10, Param11, Param12, Param13)
    print('TestLuaOverrideBPFunction in lua')
    print('Param1:', Param1)
    print('Param2:', Param2)
    print('Param3:', Param3)
    print('Param4:', Param4)
    print('Param5:', Param5)
    print('Param6:', Param6)
    print('Param7:', Param7)
    print('Param8:', Param8.X, Param8.Y, Param8.Z)
    print('Param9:', Param9.Yaw, Param9.Roll, Param9.Pitch)

    print('Param10 Location:', Param10.Translation.X, Param10.Translation.Y, Param10.Translation.Z)
    print('Param10 Rotation:', Param10.Rotation.X, Param10.Rotation.Y, Param10.Rotation.Z)
    print('Param10 Scale:', Param10.Scale3D.X, Param10.Scale3D.Y, Param10.Scale3D.Z)
    print('Param11:', Param11)

    for i, v in ipairs(Param12) do
        print('Param12', i, v)
    end

    for i, v in ipairs(Param13) do
        print('Param13', i, v)
    end

    local KismetMathLibrary = LoadClass('KismetMathLibrary')

    Param1 = not Param1
    Param2 = Param2 + 100
    Param3 = Param3 + 100
    Param4 = Param4 + 100
    Param5 = '150'
    Param6 = '160'
    Param7 = '170'

    Param8 = KismetMathLibrary:MakeVector(180, 180, 180)
    Param9 = KismetMathLibrary:MakeRotator(190, 190, 190)

    Param12 = {5, 4, 3, 2, 1}
    return Param12, Param1, Param2, Param3, Param4, Param5, Param6, Param7, Param8, Param9, Param10, Param11, Param12, Param13
end

function m:TestFunction2(Param1, Param2)
    print('TestFunction2 in lua', Param1, Param2)
    return Param1, Param2
end

function m:OnInitBPFunctionOverriding()
    return {
        'TestLuaOverrideBPFunction',
        'TestFunction2',
    }
end

return m