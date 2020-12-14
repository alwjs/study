//
//  STRootVC.m
//  CourseProject
//
//  Created by 王继昇 on 2020/12/14.
//

#import "STRootVC.h"
#import "STSubVC.h"

@interface STRootVC ()
@property (weak, nonatomic) IBOutlet UITableView *showTbv;

@end

@implementation STRootVC

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"培训课程";
    // Do any additional setup after loading the view from its nib.
    
}

/*
 #pragma mark - Navigation
 
 // In a storyboard-based application, you will often want to do a little preparation before navigation
 - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
 // Get the new view controller using [segue destinationViewController].
 // Pass the selected object to the new view controller.
 }
 */




#pragma mark - UITableViewDelegate

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    return 50;
}
- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    return 0.1;
    
}
- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section{
    return 0.1;
}
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
    
    STSubVC *vc = [[STSubVC alloc]init];
    vc.courseType = (CourseType) indexPath.row;
    UITableViewCell *cell=  [_showTbv cellForRowAtIndexPath:indexPath];
    vc.navigationItem.title = cell.textLabel.text;
    [self.navigationController pushViewController:vc animated:YES];
    
}



#pragma mark - UITableViewDataSource
-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    
    return 1;
    
}
-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return 8;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"TbvCell"];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"TbvCell"];
    }
    
    switch (indexPath.row) {
        case 0:
        {
            cell.textLabel.text = @"证书";
            return cell;
        }
            break;
        case 1:
        {
            cell.textLabel.text = @"Git";
            
            return cell;
        }
            break;
        case 2:
        {
            cell.textLabel.text = @"框架搭建";
            
            return cell;
        }
            break;
        case 3:
        {
            cell.textLabel.text = @"CocoaPods";
            
            return cell;
        }
            break;
        case 4:
        {
            cell.textLabel.text = @"OC";
            
            return cell;
        }
            break;
        case 5:
        {
            cell.textLabel.text = @"UI";
            
            return cell;
        }
            break;
        case 6:
        {
            cell.textLabel.text = @"Masonry框架应用";
            
            return cell;
        }
            break;
        case 7:
        {
            cell.textLabel.text = @"Flutter框架应用";
            
            return cell;
        }
            break;
            
        default:
            break;
    }
    
    
    
    
    return [UITableViewCell new];
    
}

@end
