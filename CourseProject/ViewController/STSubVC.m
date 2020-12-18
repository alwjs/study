//
//  STSubVC.m
//  CourseProject
//
//  Created by 王继昇 on 2020/12/14.
//

#import "STSubVC.h"
#import "STDebugModel.h"

@interface STSubVC ()

@end

@implementation STSubVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    switch (_courseType) {
        case Course_Build:
        {
            STDebugModel *debugModel = [[STDebugModel alloc] init];

            
        }
            break;
            
        default:
            break;
    }
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
