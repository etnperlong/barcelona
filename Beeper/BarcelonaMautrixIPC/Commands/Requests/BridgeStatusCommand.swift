//
//  BridgeStatusCommand.swift
//  BarcelonaMautrixIPC
//
//  Created by Eric Rabil on 8/6/21.
//  Copyright © 2021 Eric Rabil. All rights reserved.
//

import Foundation
import Barcelona
import BarcelonaEvents
import IMCore
import IMFoundation

public enum BridgeState: String, Codable {
    case starting = "STARTING"
    case unconfigured = "UNCONFIGURED"
    case connecting = "CONNECTING"
    case backfilling = "BACKFILLING"
    case connected = "CONNECTED"
    case transientDisconnect = "TRANSIENT_DISCONNECT"
    case badCredentials = "BAD_CREDENTIALS"
    case unknownError = "UNKNOWN_ERROR"
    case loggedOut = "LOGGED_OUT"
}

public struct BridgeStatusCommand: Codable, Equatable {
    public var state_event: BridgeState
    public var ttl: TimeInterval
    public var error: String?
    public var message: String?
    public var remote_id: String?
    public var remote_name: String?
}

private extension IMAccount {
    var isPlaceholder: Bool {
        uniqueID == "PlaceholderAccount"
    }
}

private extension IMAccountController {
    /// Returns an interpretation of login status, or bad credentials if a registration failure is present
    var state: BridgeState {
        guard let account = iMessageAccount else {
            return .unconfigured
        }
        
        guard !account.isPlaceholder else {
            return .unconfigured
        }
        
        var isProcessing: Bool {
            if IMServiceImpl.iMessage().status() == .loggingIn {
                return true
            }
            
            switch account.registrationStatus {
            case .unregistered:
                return true
            case .authenticating:
                return true
            case .authenticated:
                return true
            case .registering:
                return true
            default:
                return false
            }
        }
        
        switch account.loginStatus {
        case .statusLoggedOut:
            if isProcessing {
                return .connecting
            } else {
                return .unconfigured
            }
        case .statusDisconnected:
            return .transientDisconnect
        case .statusLoggingOut:
            return .loggedOut
        case .statusLoggingIn:
            return .connecting
        case .statusLoggedIn:
            switch account.registrationStatus {
            case .failed:
                switch account.registrationFailureReason {
                case .noError:
                    fallthrough
                case .unknownError:
                    return .connecting
                default:
                    return .badCredentials
                }
            case .unknown:
                return .connecting
            case .unregistered:
                return .connecting
            case .authenticating:
                return .connecting
            case .authenticated:
                return .connecting
            case .registering:
                return .connecting
            case .registered:
                return .connected
            @unknown default:
                return .unknownError
            }
        @unknown default:
            return .unknownError
        }
    }
    
    /// Translates IMCore enum to string error messages
    var error: String? {
        guard let account = iMessageAccount else {
            return nil
        }
        
        switch account.registrationFailureReason {
        case .noError:
            return nil
        case .unknownError:
            return nil
        case .invalidLogin:
            return "invalid_login"
        case .invalidPassword:
            return "invalid_password"
        case .loginFailed:
            return "login_failed"
        case .cannotConnect:
            return "cannot_connect"
        case .badDeviceID:
            return "bad_device_id"
        case .badPushToken:
            return "bad_push_token"
        case .serverDenied:
            return "server_denied"
        case .tooManyAttempts:
            return "too_many_attempts"
        case .accountUpdateNeeded:
            return "account_update_needed"
        case .accountNotAuthorized:
            return "account_not_authorized"
        case .newPasswordNeeded:
            return "new_password_needed"
        case .permanentlyBlocked:
            return "permanently_blocked"
        case .temporarilyBlocked:
            return "temporarily_blocked"
        case .cancelled:
            return "cancelled"
        case .notSupported:
            return "not_supported"
        case .badDeviceCredentials:
            return "bad_device_credentials"
        case .expiredDeviceCredentials:
            return "expired_device_credentials"
        case .serverError:
            return "server_error"
        case .unconfirmedAlias:
            return "unconfirmed_alias"
        case .registrationUnsupported:
            return "registration_unsupported"
        case .registrationNoAliasesSpecified:
            return "registration_no_aliases_specified"
        case .unsupportedManagedID:
            return "unsupported_managed_id"
        case .disabledSMSAuthentication:
            return "disabled_sms_authentication"
        case .deniedByServer:
            return "denied_by_server"
        case .badCredentials:
            return "bad_credentials"
        case .irreparableFailure:
            return "irreparable_failure"
        @unknown default:
            return "unknown_error"
        }
    }
    
    var message: String? {
        iMessageAccount?.registrationFailureAlertInfo?[IMAccountRegistrationFailedAlertMessageKey] as? String
    }
}

public extension BridgeStatusCommand {
    static var current: BridgeStatusCommand {
        let account = IMAccountController.shared.iMessageAccount
        let state = IMAccountController.shared.state
        
        return BridgeStatusCommand(
            state_event: state,
            ttl: state == .connected ? 3600 : 240,
            error: IMAccountController.shared.error,
            message: IMAccountController.shared.message,
            remote_id: account?.strippedLogin ?? nil, // Apple ID – absent when unconfigured. logged out includes the remote id, and then goes to unconfigured. everything else must include the remote ID
            remote_name: IMMe.me().fullName // Account Name
        )
    }
}