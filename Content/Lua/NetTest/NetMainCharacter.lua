local m = {}

-- parent UObject
local Super = Super

-- global functions
local LoadClass = LoadClass

function m:ReceiveBeginPlay()
    print('NetMainCharacter begin play in lua')
end

function m:OnSetupPlayerInputComponent()
    local BlueluaLibrary = LoadClass('BlueluaLibrary')

    local EInputEvent = {
        IE_Pressed = 0,
        IE_Released = 1,
        IE_Repeat = 2,
        IE_DoubleClick = 3,
        IE_Axis = 4,
        IE_MAX = 5,
    }

    -- Press P key to start ent test
    BlueluaLibrary:BindKeyAction(Super, { Key = { KeyName = 'P' } }, EInputEvent.IE_Pressed, true, false, CreateFunctionDelegate(Super, self, self.OnKeyPressed))
end

function m:OnKeyPressed()
    -- test net event in c++
    Super:TestNativeClientFunction() -- will run on current client
    Super:TestNativeNetMulticastFunction() -- will run on current client
    Super:TestNativeServerFunction() -- will run on remote server

    -- test net event in blueprint
    Super:TestBPClientFunction() -- will run on current client
    Super:TestBPNetMulticastFunction() -- will run on current client
    Super:TestBPServerFunction() -- will run on remote server
end

-- override Server replicated event in c++
function m:TestNativeClientFunction()
    print('TestNativeClientFunction get called')
end

-- override NetMulticast replicated event in c++
function m:TestNativeNetMulticastFunction()
    print('TestNativeNetMulticastFunction get called')
end

-- override Client replicated event in c++
function m:TestNativeServerFunction()
    print('TestNativeServerFunction get called')
    Super:TestNativeNetMulticastFunction() -- will run on local server and remote client
    Super:TestNativeClientFunction() -- will run on remote client
end

-- override Server replicated event in blueprint
function m:TestBPClientFunction()
    print('TestBPClientFunction get called')
end

-- override NetMulticast replicated event in blueprint
function m:TestBPNetMulticastFunction()
    print('TestBPNetMulticastFunction get called')
end

-- override Client replicated event in blueprint
function m:TestBPServerFunction()
    print('TestBPServerFunction get called')
    Super:TestBPNetMulticastFunction() -- will run on local server and remote client
    Super:TestBPClientFunction() -- will run on remote client
end

return m