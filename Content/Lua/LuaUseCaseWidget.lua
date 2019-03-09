local m = {}

local Super = Super
local print = print
local LoadClass = LoadClass
local CreateFunctionDelegate = CreateFunctionDelegate
local DeleteFunctionDelegate = DeleteFunctionDelegate

local KismetSystemLibrary = LoadClass('KismetSystemLibrary')

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
    self.Button1ClickedDelegate = self.Button1ClickedDelegate or CreateFunctionDelegate(Super, function() print('Button1 OnClicked') end)
    Super.Button1.OnClicked:Clear()
    Super.Button1.OnClicked:Add(self.Button1ClickedDelegate)

    self.TimerDelegate = self.TimerDelegate or CreateFunctionDelegate(Super, self, self.DelegateCallback)
    KismetSystemLibrary:K2_SetTimerDelegate(self.TimerDelegate, 1, true)

    Super:TestFunction2(false, 200)
end

local count = 0
function m:DelegateCallback()
    count = count + 1
    print('DelegateCallback', tostring(self), count)
    if count >= 10 and self.TimerDelegate then
        KismetSystemLibrary:K2_ClearTimerDelegate(self.TimerDelegate)
        DeleteFunctionDelegate(self.TimerDelegate)
        self.TimerDelegate = nil
    end
end

-- Override UserWidget Destruct Event
function m:Destruct()
    print('LuaUseCaseWidget Destruct')
end

-- Override UseCaseWidget TestBlueprintImplementableEvent Event
function m:TestBlueprintImplementableEvent(Param)
    print('TestBlueprintImplementableEvent in lua')
    Super:TestBlueprintImplementableEvent_Default(Param)
    return Param
end

-- Override UseCaseWidget TestBlueprintNativeEvent1 Event
function m:TestBlueprintNativeEvent1(Param)
    print('TestBlueprintNativeEvent1 in lua')
    Super:TestBlueprintNativeEvent1_Default(Param)
    return Param
end

-- Override UseCaseWidget TestBlueprintNativeEvent2 Event
function m:TestBlueprintNativeEvent2(Param)
    print('TestBlueprintNativeEvent2 in lua')
    Super:TestBlueprintNativeEvent2_Default(Param)
    return Param
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